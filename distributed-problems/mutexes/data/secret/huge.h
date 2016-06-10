//Author: Stefan Toman

int NumberOfOperations(long long i) {
  return 40000;
}

int GetOperation(long long i, long long index) {
  if(index < NumberOfOperations(i) - 2) return 3 + index + i * NumberOfOperations(0);
  else if(index == NumberOfOperations(i) - 2) return i + 1;
  else if(index == NumberOfOperations(i) - 1) return 2 - i;
}
