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

double dp[101][601];

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j <= 6 * i; j++) {
            for (int k = 1; k <= 6; k++) {
                dp[i + 1][j + k] += dp[i][j] / 6;
            }
        }
    }

    double res = 0;

    for (int i = a; i <= b; i++) {
        res += dp[n][i];
    }

    cout << fixed << setprecision(6) << res << endl;
}