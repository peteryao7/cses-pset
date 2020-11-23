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
    ll sum = 0, most = 0;

    while (n--) {
        ll t;
        cin >> t;
        sum += t;
        most = max(most, t);
    }

    cout << max(sum, 2 * most) << endl;
}