// Sample input 2, in CPP.

#include <cassert>

long long GetN() {
  return 2LL;
}

long long GetVote(long long i) {
  switch ((int)i) {
    case 0: return 10LL;
    case 1: return 20LL;
    default: assert(0);
  }
}
