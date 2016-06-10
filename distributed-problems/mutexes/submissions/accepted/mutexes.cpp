//Author: Stefan Toman

#include <message.h>
#include "mutexes.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = NumberOfOperations(0);
  int m = NumberOfOperations(1);
  int x = 10*64;
  
  if(me < nodes - 1) {
    int from = n / (nodes - 1) * me;
    int to = me == nodes -2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;
    //cerr << "from " << from << " to " << to << endl;
  
    vector<vector<bool>> valid(to - from + 2, vector<bool> (m + 1, true));

    long long r = LLONG_MAX;
    vector<bool> used0_template(100001, false);
    for(int i = 0; i < min(from, n); i++) {
      int tmp = GetOperation(0, i);
      used0_template[abs(tmp)] = tmp > 0;
    }
    
    vector<bool> used1(100001, false);
    int usedtwice_template = 0, sent = 0, received = 0;
    for(int j = 0; j < m + 1; j++) {
      if(me > 0 && received < j) {
        Receive(me - 1);
        int receive = GetInt(me - 1);
        received += receive;
        long long next = 0;
        for(int k = j; k < j + receive; k++) {
          if((k - j) % 64 == 0) next = GetLL(me - 1);
          valid[0][k] = next % 2;
          next = next >> 1;
        }        
        //cerr << j << endl;
      }
    
      int usedtwice = usedtwice_template;
      vector<bool> used0 = used0_template;
      for(int i = from; i <= to; i++) {
        int tmp = GetOperation(0, i);
        used0[abs(tmp)] = tmp > 0;
        if(tmp > 0 && used1[abs(tmp)]) usedtwice++;
        if(tmp < 0 && used1[abs(tmp)]) usedtwice--;

        valid[i - from + 1][j] = (valid[i - from][j] || valid[i - from + 1][j-1]) && usedtwice == 0;
        
        if(valid[i - from + 1][j] && i + 1 < n && j < m && r > i + j + 3) {
          int tmp = GetOperation(0, i + 1);
          if(tmp > 0 && used1[tmp]) {
            tmp = GetOperation(1, j);
            if(tmp > 0 && used0[tmp]) {
              r = i + j + 3;
            }
          }
        }
      }
      
      if(j < m) {
        int tmp = GetOperation(1, j);
        used1[abs(tmp)] = tmp > 0;
        if(tmp > 0 && used0_template[abs(tmp)]) usedtwice_template++;
        if(tmp < 0 && used0_template[abs(tmp)]) usedtwice_template--;
      }
      
      if(me < nodes - 2 && (j % x == 0 || j == m)) {
        int send = j - sent + 1;
        sent += send;
        PutInt(me + 1, send);
        long long next = 0;
        int digits = 0;
        for(int  k = j - send + 1; k <= j; k++) {
          if(digits == 64) {
            PutLL(me + 1, next);
            next = 0LL;
            digits = 0;
          }
          next |= (long long) valid[to - from + 1][k] << digits;
          digits++;
        }
        PutLL(me + 1, next);
        Send(me + 1);
      }
    }
    
    /*for(int i = from + (me > 0 ? 1 : 0); i <= to + 1; i++) {
      for(int j = 0; j < m + 1; j++) {
        cerr << valid[i - from][j] << " ";
      }
      cerr << endl;
    }*/
    
    PutLL(nodes - 1, r);
    Send(nodes - 1);
  }
  else {
    long long r = LLONG_MAX;

    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      r = min(r, GetLL(i));
    }

    cout << (r == LLONG_MAX ? "OK" : to_string(r)) << endl;
  }
  
  return 0;
}