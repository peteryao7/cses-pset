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
    int max = 1e6 + 1;
    vi factors(max);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        factors[x]++;
    }

    int res = 1;

    for (int i = 2; i < max; i++) {
        int cur = 0;

        // sieve
        for (int j = i; j < max; j += i)
            cur += factors[j];

        if (cur >= 2)
            res = i;
    }

    cout << res << endl;
}