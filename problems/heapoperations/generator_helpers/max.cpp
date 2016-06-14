//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
  int n = 100000;
  cout << n << endl;
  for(int i = 0; i < n/2; i++) cout << "insert 1" << endl;
  for(int i = 0; i < n/2; i++) cout << "getMin 0" << endl;
}