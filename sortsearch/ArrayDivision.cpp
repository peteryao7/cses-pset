#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    ll x[n];
    ll mv = 0;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
        mv = max(mv, x[i]);
    }

    ll l = mv, r = 1e18;

    while (l < r) {
        ll mid = l + (r - l) / 2;

        int subarrays = 1;
        ll subsum = 0;

        for (int i = 0; i < n; i++) {
            if (subsum + x[i] > mid) {
                subarrays++;
                subsum = 0;
            }
            subsum += x[i];
        }

        if (subarrays > k)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << endl;
}