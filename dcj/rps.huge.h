long long GetN() {
  return 28;
}

char GetFavoriteMove(long long id) {
  switch ((int) (id % 3)) {
    case 0: return 'S';
    case 1: return 'P';
    case 2: return 'R';
  }
}
                  