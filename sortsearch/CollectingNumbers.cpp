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

int main() {
    int n;
    cin >> n;
    vi idx(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        idx[--x] = i;
    }

    int res = 1;
    for (int i = 1; i < n; i++) {
        if (idx[i] < idx[i - 1])
            res++;
    }

    cout << res << endl;
} 