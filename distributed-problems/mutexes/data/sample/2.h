// Sample input 2, in CPP.

#include <cassert>

int NumberOfOperations(long long i) {
  switch ((int)i) {
    case 0: return 5;
    case 1: return 2;
    default: assert(0);
  }
}

int GetOperation(long long i, long long index) {
  if (i == 0 && index == 0) return 10;
  if (i == 0 && index == 1) return -10;
  if (i == 0 && index == 2) return 10;
  if (i == 0 && index == 3) return 20;
  if (i == 0 && index == 4) return 30;
  if (i == 1 && index == 0) return 30;
  if (i == 1 && index == 1) return 10;
  assert(0);
}
