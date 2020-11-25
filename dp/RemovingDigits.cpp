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
    vi dp(n + 1, n);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j /= 10) {
            dp[i] = min(dp[i], dp[i - j % 10] + 1);
        }
    }

    cout << dp[n] << endl;
}