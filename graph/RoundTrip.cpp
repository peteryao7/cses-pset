#include <iostream>
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

const int mx = 1e5 + 1;
int n, m, p[mx];
vi adj[mx], res;
bool visited[mx];

// find a cycle
void dfs(int u, int parent) {
    p[u] = parent;
    visited[u] = 1;

    for (int v : adj[u]) {
        if (v == parent)
            continue;
        if (visited[v]) {
            int breakpt = u;
            while (u != v) {
                res.push_back(u);
                u = p[u];
            }
            res.push_back(v);
            res.push_back(breakpt);
            cout << res.size() << endl;
            for (int r : res)
                cout << r + 1 << " ";
            cout << endl;
            exit(0);
        }
        else {
            dfs(v, u);
        }
    }
}

int main() {
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    cout << "IMPOSSIBLE\n";
}