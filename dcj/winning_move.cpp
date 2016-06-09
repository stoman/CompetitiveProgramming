//Author: Stefan Toman

#include <message.h>
#include "winning_move.h"

#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long hashf(long long x, int nodes) {
  x = ((x >> 32) ^ x) * 0x45d9f3bLL;
  x = ((x >> 32) ^ x) * 0x45d9f3bLL;
  x = ((x >> 32) ^ x);
  if(x < 0) x *= -1;
  return x % nodes;
}

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = GetNumPlayers();
  
  if(me < nodes - 1) {
    int from = n / (nodes - 1) * me;
    int to = me == nodes -2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;

    map<long long, int> subsa, subsb;
    vector<vector<long long>> send(nodes - 1);
    for(int i = from; i <= to; i++) {
      long long x = GetSubmission(i);
      subsa[x]++;
      if(subsa[x] <= 2) send[hashf(x, nodes - 1)].push_back(x);
    }
    
    for(int i = 0; i < nodes - 1; i++) {
      PutLL(i, send[i].size());
      for(long long t: send[i]) PutLL(i, t);
      Send(i);
    }
    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      int s = GetLL(i);
      for(int j = 0; j < s; j++) {
        long long tmp = GetLL(i);
        subsb[tmp]++;
      }
    }
    
    long long min = LLONG_MAX;
    for(auto p: subsb) if(p.second == 1 && min > p.first) min = p.first;
    PutLL(nodes - 1, min);
    Send(nodes - 1);
  }
  else {
    long long min = LLONG_MAX;

    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      long long tmp = GetLL(i);
      if(min > tmp) min = tmp;
    }

    cout << (min == LLONG_MAX ? 0 : min) << endl;
  }
  
  return 0;
}