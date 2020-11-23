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

    int s[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s + n);
    ll mid = s[n / 2];
    ll res = 0;

    for (int i = 0; i < n; i++) {
        res += abs(s[i] - mid);
    }

    cout << res << endl;
}