#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    if (s[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }

    ll dp[n + 1][n + 1];
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i || j)
                dp[i][j] = 0;

            if (s[i][j] == '*')
                continue;

            if (i)
                dp[i][j] += dp[i - 1][j];
            if (j)
                dp[i][j] += dp[i][j - 1];

            dp[i][j] %= M;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}