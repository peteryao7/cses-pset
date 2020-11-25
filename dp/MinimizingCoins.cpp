#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int main() {
    int n, x;
    cin >> n >> x;
    int coins[n];
    vector<int> dp(x + 1, 1e6 + 1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[x] == 1e6 + 1)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
}