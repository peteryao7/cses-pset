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

const int mx = 2e5 + 1;
int sub[mx];
vi adj[mx];

void dfs(int u, int p) {
    sub[u] = 1;

    for (int v : adj[u]) {
        dfs(v, u);
        sub[u] += sub[v];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++)
        cout << sub[i] - 1 << " ";

    cout << endl;
}