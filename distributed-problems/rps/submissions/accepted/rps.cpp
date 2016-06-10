//Author: Stefan Toman

#include <message.h>
#include "rps.h"

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

long long winner(long long a, long long b) {
  char ca = GetFavoriteMove(a), cb = GetFavoriteMove(b);
  if(ca == 'R' && cb == 'S') return a;
  else if(ca == 'S' && cb == 'P') return a;
  else if(ca == 'P' && cb == 'R') return a;
  else if(cb == 'R' && ca == 'S') return b;
  else if(cb == 'S' && ca == 'P') return b;
  else if(cb == 'P' && ca == 'R') return b;
  else return a;
}

long long winnerrange(long long a, long long b) {
  if(a == b) return a;
  if(a + 1 == b) return winner(a, b);
  else return winner(winnerrange(a, (a+b)/2), winnerrange((a+b)/2 + 1, b));
}

int main() {
  int nodes = NumberOfNodes();
  int me = MyNodeId();
  int n = GetN();
  
  int working = nodes == 100 ? 64 : 8;
  long long players = 1 << n;
  if(working > players) working = players;
  
  if(me < working) {
    PutLL(nodes - 1, winnerrange(players / working * me, players / working * (me + 1) - 1));
    //cerr << "winner between " << players / working * me << " and " << players / working * (me + 1) - 1 << ": " << winnerrange(players / working * me, players / working * (me + 1) - 1) << endl;
    Send(nodes - 1);
  }
  else if(me == nodes - 1) {
    vector<long long> p;
    
    for(int i = 0; i < working; i++) {
      Receive(i);
      p.push_back(GetLL(i));
    }
    while(working > 1) {
      working /= 2;
      for(int i = 0; i < working; i++) {
        //cerr << "winner between " << p[2*i] << " and " << p[2*i+1] << ": " << winner(p[2*i], p[2*i+1]) << endl;
        p[i] = winner(p[2*i], p[2*i+1]);
      }
    }
    cout << p[0] << endl;
  }
  
  return 0;
}