#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<array<int, 2>> s;

    while (n--) {
        int a, b;
        cin >> a >> b;
        s.insert({a, 1});
        s.insert({b, -1});
    }

    int res = 0, cur = 0;

    for (array<int, 2> a : s) {
        cur += a[1];
        res = max(res, cur);
    }

    cout << res << endl;
}