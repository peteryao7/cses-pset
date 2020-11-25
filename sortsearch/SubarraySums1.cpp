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
    int n, x;
    cin >> n >> x;
    int a[n];

    ll sum = 0;
    map<ll, int> map;
    map[0]++;

    ll res = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        res += map[sum - x];
        map[sum]++;
    }

    cout << res << endl;
}