//Author: Stefan Toman

#include <message.h>
#include "crates.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007LL;

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = GetNumStacks();
  
  if(me < nodes - 1) {
    int from = n / (nodes - 1) * me;
    int to = me == nodes - 2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;
  
    long long sum = 0, length = to - from + 1;
    for(int i = from; i <= to; i++) {
      sum += GetStackHeight(i+1);
    }
    PutLL(nodes - 1, sum);
    PutLL(nodes - 1, length);
    Send(nodes - 1);
    
    Receive(nodes - 1);
    long long fromleft = GetLL(nodes - 1);
    long long toright = GetLL(nodes - 1);

    long long moves = 0;

    if(length > 0) {
      long long crates = sum + fromleft - toright;
      long long additional = crates - (crates / length) * length;
      //cerr << "working from " << from << " to " << to << ", sum: " << sum << ", get from left: " << fromleft << ", push to right: " << toright << ", crates: " << crates << endl;
      
      for(int i = from; i <= to; i++) {
        moves += abs(fromleft);
        moves %= mod;
        fromleft = GetStackHeight(i+1) + fromleft - crates / length - (i - from < additional ? 1 : 0);
      }
    }
    //cerr << moves << " moves" << endl;
    PutLL(nodes - 1, moves);
    Send(nodes - 1);
  }
  else {
    long long sum = 0;
    vector<long long> sums, sizes;
    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      sums.push_back(GetLL(i));
      sizes.push_back(GetLL(i));
      sum += sums[i];
    }
    long long perstack = sum / n;
    long long remaining = sum - n * perstack;
    long long open = 0;
    for(int i = 0; i < nodes - 1; i++) {
      long long additional = min(remaining, sizes[i]);
      remaining -= additional;
      long long needs = sizes[i] * perstack + additional;
      PutLL(i, open);
      open += sums[i] - needs;
      PutLL(i, open);
      Send(i);
    }

    long long moves = 0;
    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      moves = (moves + GetLL(i)) % mod;
    }
    cout << moves << endl;
  }
  
  return 0;
}