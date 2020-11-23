#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n, t;
    cin >> n >> t;
    int times[n];

    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    ll l = 1, r = 1e18;

    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            sum += min(mid / times[i], (ll) 1e9);
        }

        if (sum >= t) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << endl;
}