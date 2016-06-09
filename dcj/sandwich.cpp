//Author: Stefan Toman

#include <message.h>
#include "sandwich.h"

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
  
    long long sum = 0;
    long long biggest = 0;//from left
    long long smallest = 0;//from left
    long long min = 0;//somewhere inside
    
    for(int i = from; i <= to; i++) {
      sum += GetTaste(i);
      if(biggest < sum) biggest = sum;
      if(smallest > sum) smallest = sum;
      if(min > sum - biggest) min = sum - biggest;
      }
    
    PutLL(nodes - 1, sum);
    PutLL(nodes - 1, smallest);
    PutLL(nodes - 1, biggest);
    PutLL(nodes - 1, min);
    Send(nodes - 1);
  }
  else {
    vector<long long> sum, smallest, biggest, min;
    for(int i = 0; i < nodes - 1; i++) {
      Receive(i);
      sum.push_back(GetLL(i));
      smallest.push_back(GetLL(i));
      biggest.push_back(GetLL(i));
      min.push_back(GetLL(i));
    }

    long long total = 0, r = LLONG_MIN;
    for(int i = 0; i < nodes - 1; i++) total += sum[i];
    
    for(int start = 0; start < nodes - 1; start++) {
      if(r < total - min[start]) r = total - min[start];
      for(int end = start + 1; end < nodes - 1; end++) {
        long long tmp = sum[start] - biggest[start];
        for(int i = start + 1; i < end; i++) tmp += sum[i];
        tmp += smallest[end];
        
        if(r < total - tmp) r = total - tmp;
      }
    }
    
    cout << r << endl;
  }
  
  return 0;
}