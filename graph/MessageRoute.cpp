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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

const int mx = 2e5;
// p holds path from 0 to n - 1
int n, m, p[mx];
vi adj[mx];

int main() {
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(p, -1, 2*mx);

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (p[v] < 0) {
                p[v] = u;
                q.push(v);
            }
        }
    }

    vi res;

    if (p[n - 1] < 0) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        int u = n - 1;
        while (u) {
            res.push_back(u);
            u = p[u];
        }

        res.push_back(0);
        reverse(res.begin(), res.end());
        cout << res.size() << endl;

        for (int r : res) {
            cout << r + 1 << " ";
        }
        cout << endl;
    }
}