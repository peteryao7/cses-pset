#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int nimSum = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (i & 1) nimSum ^= x;
        }

        if (nimSum) cout << "first" << endl;
        else cout << "second" << endl;
    }
}