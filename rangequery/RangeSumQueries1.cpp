#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

int main() {
    int n, q;
    cin >> n >> q;

    ll x[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << x[b] - x[a - 1] << endl;
    }
}