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
typedef pair<int, int> pii;

const int M = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    vi val(n + 1);
    vi idx(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        val[i] = x;
        idx[x] = i;
    }

    int res = 1;
    for (int i = 2; i <= n; i++) {
        if (idx[i] < idx[i - 1])
            res++;
    }

    while (m--) {
        set<pii> pairs;
        int l, r;
        cin >> l >> r;
        
        if (val[l] + 1 <= n)
            pairs.insert(make_pair(val[l], val[l] + 1));
        if (val[l] - 1 >= 1)
            pairs.insert(make_pair(val[l] - 1, val[l]));
        if (val[r] + 1 <= n)
            pairs.insert(make_pair(val[r], val[r] + 1));
        if (val[r] - 1 >= 1)
            pairs.insert(make_pair(val[r] - 1, val[r]));

        for (pii pair : pairs) {
            if (idx[pair.first] > idx[pair.second])
                res--;
        }

        swap(val[l], val[r]);
        idx[val[l]] = l;
        idx[val[r]] = r;

        for (pii pair : pairs) {
            if (idx[pair.first] > idx[pair.second])
                res++;
        }

        cout << res << endl;
    }
}