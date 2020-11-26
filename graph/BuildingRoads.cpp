#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

const int mx = 1e5 + 1;
vector<int> adj[mx], res;
bool visited[mx];

void dfs(int u) {
    visited[u] = 1;

    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // explore new CC
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            res.push_back(i);
            dfs(i);
        }
    }

    cout << res.size() - 1 << endl;
    // connect all other SCCs to first node of first SCC 
    for (int i = 1; i < res.size(); i++)
        cout << res[0] + 1 << " " << res[i] + 1 << endl;
}