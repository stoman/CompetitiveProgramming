//Author: Stefan Toman

#include <message.h>
#include "almost_sorted.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

const long long mod = (1 << 20) - 1;

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = NumberOfFiles();
  
  if(me < nodes - 1) {
    int from = n / (nodes - 1) * me;
    int to = me == nodes -2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;
  
    long long offset_left = min(MaxDistance(), (long long) from);
    long long offset_right = min(MaxDistance(), (long long) (n - to - 1));

    vector<long long> data;   
    for(int i = from - offset_left; i <= to + offset_right; i++) {
      data.push_back(Identifier(i));
    }
    sort(data.begin(), data.end());
    
    long long r = 0;
    for(int i = from; i <= to; i++) {
      r += i * data[i - from + offset_left];
      r &= mod;
    }
    
    PutLL(nodes - 1, r);
    Send(nodes - 1);
  }
  else {
    long long r = 0;

    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      r += GetLL(i);
      r &= mod;
    }

    cout << r << endl;
  }
  
  return 0;
}