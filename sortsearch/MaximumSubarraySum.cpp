#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll res, cur;
    cin >> res;
    cur = res;

    for (int i = 1; i < n; i++) {
        ll x;
        cin >> x;
        cur = max(x, cur + x);
        res = max(res, cur);
    }

    cout << res << endl;
}