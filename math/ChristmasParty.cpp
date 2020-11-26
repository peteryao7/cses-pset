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
typedef vector<ll> vll;
const int M = 1e9 + 7;

// find derangements
// CSES pg 214
int main() {
    int n;
    cin >> n;

    vll dp(n + 1);
    dp[0] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = ((i - 1) * dp[i - 1] + (i - 1) * dp[i - 2]) % M;
    }

    cout << dp[n] << endl;
}