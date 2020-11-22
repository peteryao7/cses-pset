#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    while (true) {
        if (n == 1) {
            cout << n << endl;
            return 0;
        }
        cout << n << ' ';
        n = n % 2 ? n * 3 + 1 : n / 2;
    }
}