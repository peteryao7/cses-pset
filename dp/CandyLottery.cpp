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
    int n, k;
    cin >> n >> k;
    ld res = 0;

    // sum(i=1, k) i * ((i/k)^n - ((i-1)/k)^n)
    for (int i = 1; i <= k; i++) {
        ld probMax = 1, probNotMax = 1;
        for (int j = 0; j < n; j++ ) {
            probMax *= (ld) i / (ld) k;
            probNotMax *= (ld) (i - 1) / (ld) k;
        }
        res += (ld) i * (probMax - probNotMax);
    }

    cout << fixed << setprecision(6) << res << endl;
}