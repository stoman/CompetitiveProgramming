//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
    int n;
    long long s = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        s += t;
    }
    cout << s << endl;
    return 0;
}
