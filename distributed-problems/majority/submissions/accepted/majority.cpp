//Author: Stefan Toman

#include <message.h>
#include "majority.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  long long n = GetN();
  
  if(me < nodes - 1) {
    long long from = n / (nodes - 1) * me;
    long long to = me == nodes - 2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;
  
    map<long long, long long> votes;
    for(long long i = from; i <= to; i++) votes[GetVote(i)]++;
    
    long long max = -1;
    for(auto& t: votes) if(2 * t.second > to - from + 1) max = t.first;
    
    PutLL(nodes - 1, max);
    Send(nodes - 1);
    
    Receive(nodes - 1);
    int c = GetInt(nodes - 1);
    for(int i = 0; i < c; i++) PutLL(nodes - 1, votes[GetLL(nodes - 1)]);
    Send(nodes - 1);
  }
  else {
    vector<long long> max;
    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      long long winner = GetLL(i);
      if(winner > -1) max.push_back(winner);
    }

    for(int i = 0; i < nodes - 1; i++) {
      PutInt(i, max.size());
      for(int j = 0; j < max.size(); j++) PutLL(i, max[j]);
      Send(i);
    }

    vector<long long> votes(max.size(), 0);

    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      for(int j = 0; j < max.size(); j++) votes[j] += GetLL(i);
    }

    long long win = -1;
    for(int j = 0; j < max.size(); j++) if(2 * votes[j] > n) win = max[j];

    cout << (win == -1 ? "NO WINNER" : to_string(win)) << endl;
  }
  
  return 0;
}