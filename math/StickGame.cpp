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

    vi dp(n + 1);
    int moves[k];

    for (int i = 0; i < k; i++) {
        cin >> moves[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (i - moves[j] >= 0 && dp[i - moves[j]] == 0)
                dp[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] == 1)
            cout << "W";
        else
            cout << "L";
    }

    cout << endl;
}