#include <iostream>
#include <iomanip>
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
    int n;
    cin >> n;
    vll v;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    ll res = 1;
    for (int i = 0; i < n; i++) {
        if (res < v[i])
            break;
        else
            res += v[i];
    }

    cout << res << endl;
} 