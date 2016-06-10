//Author: Stefan Toman

long long NumberOfFiles() {
  return 100000000LL;
}

long long MaxDistance() {
  return 1000000LL;
}

long long Identifier(long long i) {
  return i + 2*MaxDistance() - 2*(i % MaxDistance());
}
