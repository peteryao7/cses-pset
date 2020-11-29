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
int n, m, color[mx];
vi adj[mx], res;
bool visited[mx];

// make graph bipartite
void dfs(int u, int c) {
    if (color[u] == 0) {
        if (color[u] != c) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        return;
    }

    color[u] = c;

    for (int v : adj[u]) {
        dfs(v, c ^ 1);
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

    memset(color, -1, 4*n);

    for (int i = 0; i < n; i++) {
        if (color[i] < 0) {
            dfs(i, 0);
        }
    }

    for (int i = 0; i < n; i++)
        cout << color[i] + 1 << " ";
    cout << endl;
}