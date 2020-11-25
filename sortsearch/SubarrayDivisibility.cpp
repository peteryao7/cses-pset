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
    int n;
    cin >> n;
    int a[n];

    ll sum = 0;
    map<ll, int> map;
    map[0]++;

    ll res = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        // + n % n for neg values, eg -3 % 5 = 2, not -3
        sum = (sum + (a[i] % n + n)) % n;
        res += map[sum];
        map[sum]++;
    }

    cout << res << endl;
}