//Author: Stefan Toman

long long GetN() {
  return 1000000000LL;
}

long long GetVote(long long i) {
  if(i == 0) return 1;
  return i % 2;
}
