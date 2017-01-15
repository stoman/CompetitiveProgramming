//Author: Stefan Toman

#include <iostream>

using namespace std;

int main() {
    int t = 100;
    cout << t << endl;
    for (int i = 0; i < t; i++) {
        long long n = 300, m = 300;
        cout << n << " " << m << endl;
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                //cout << 1000000;
                cout << (i == 0 ? 1 : 1000000);
                if(j == m-1) {
                    cout << endl;
                }
                else {
                    cout << " ";
                }
            }
        }
    }
    return 0;
}
