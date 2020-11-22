#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++) {
        ll total = (i * i * (i * i - 1)) / 2;
        // 2 bad spots * 4 corners
        // 3 bad spots * 8 corners from a cardinal direction
        // 4 bad spots * n - 4 squares on the rest of a side * 4 sides
        // 4 bad spots * 4 cells diagonal from a corner
        // 6 bad spots * n - 4 cells in second row/col * 4 sides
        // 8 bad spots * (n - 4)^2 cells for the rest of the board
        // divide all by 2 to switch knights

        // 8 + 24 + 16n - 64 + 16 + 24n - 96 + 8n^2 - 64n + 128
        // 16 + 16n + 24n - 64n + 8n^2
        // 8n^2 - 24 n + 16
        // 8(n^2 - 3n + 2)
        // 8(n - 2)(n - 1) => divide by 2
        // 4(n-2)(n-1)
        ll bad = 2 * (i - 2) * 2 * (i - 1);
        cout << total - bad << endl;
    }
}