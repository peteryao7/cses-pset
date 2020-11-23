#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;

// O(n^2)
int main() {
    ll n, x;
    cin >> n >> x;
    array<ll, 2> a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    sort (a, a + n);

    for (int i = 0; i < n; i++) {
        ll x2 = x - a[i][0];

        for (int j = i + 1, k = n - 1; j < k; j++) {
            while (j < k && a[j][0] + a[k][0] > x2)
                k--;

            if (j < k && a[j][0] + a[k][0] == x2) {
                cout << a[i][1] + 1 << " " << a[j][1] + 1 << " " << a[k][1] + 1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}