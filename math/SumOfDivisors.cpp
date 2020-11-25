#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int M = 1e9 + 7;

ll choose2(ll a) {
    return a % M * ((a - 1) % M) % M * ((M + 1) / 2) % M;
}

int main() {
    ll n;
    cin >> n;
    ll res = 0;

    for (ll i = 1; i <= n; ++i) {
        ll r = n / (n / i);
        res += (n / i) % M * (choose2(r + 1) - choose2(i) + M) % M;
        i = r;
    }

    cout << res % M << endl;
}