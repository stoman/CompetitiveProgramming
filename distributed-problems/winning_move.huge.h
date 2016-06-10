//Author: Stefan Toman
//input size is divided by 100 to allow to work it with message limit 8MB, real problem has 1GB

long long GetNumPlayers() {
  return 350000LL - 1;
}

long long GetSubmission(long long playernum) {
  return 1 + playernum / 2;
}
