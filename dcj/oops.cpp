//Author: Stefan Toman

#include <message.h>
#include "oops.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = GetN();
  
  if(me < nodes - 1) {
    int from = n / (nodes - 1) * me;
    int to = me == nodes -2 ? n - 1 : n / (nodes - 1) * (me + 1) - 1;
  
    long long max = LLONG_MIN;
    long long min = LLONG_MAX;
    
    for(int i = from; i <= to; i++) {
      if(max < GetNumber(i)) max = GetNumber(i);
      if(min > GetNumber(i)) min = GetNumber(i);
    }
    
    PutLL(nodes - 1, max);
    PutLL(nodes - 1, min);
    Send(nodes - 1);
  }
  else {
    long long max = LLONG_MIN;
    long long min = LLONG_MAX;

    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      long long tmp = GetLL(i);
      if(max < tmp) max = tmp;
      tmp = GetLL(i);
      if(min > tmp) min = tmp;
    }

    cout << max - min << endl;
  }
  
  return 0;
}