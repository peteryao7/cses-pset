#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    ll x[n + 1]; // prefix sum
    x[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
    }

    set<array<ll, 2>> s;
    ll res = -1e18;

    for (int i = 0; i <= n; i++) {
        if (i >= a) {
            s.insert({x[i - a], i - a});
        }
        if (s.size()) {
            res = max(x[i] - (*s.begin())[0], res);
        }
        if (i >= b) {
            s.erase({x[i - b], i - b});
        }

    }

    cout << res << endl;
}