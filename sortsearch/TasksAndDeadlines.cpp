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
    array<int, 2> a[n]; // duration, deadline

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a, a + n);

    ll start = 0, res = 0;

    for (int i = 0; i < n; i++) {
        start += a[i][0];
        res += a[i][1] - start;
    }

    cout << res << endl;
}