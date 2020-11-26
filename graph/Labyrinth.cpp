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

// d = dir idx in dx dy
// p = dir chars
int n, m, ai, aj, bi, bj, d[1000][1000];
string grid[1000], p[1000];
int dx[4] = {1 ,0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
string ds = "DRUL";

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];

        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                ai = i, aj = j;
                grid[i][j] = '.';
            }
            if (grid[i][j] == 'B') {
                bi = i, bj = j;
                grid[i][j] = '.';
            }
        }

        p[i] = string(m, 0);
    }

    queue<array<int, 2>> q;
    q.push({ai, aj});

    while (q.size()) {
        array<int, 2> cur = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ci = cur[0] + dx[k];
            int cj = cur[1] + dy[k];

            if (!valid(ci, cj))
                continue;

            q.push({ci, cj});
            grid[ci][cj] = '#';
            d[ci][cj] = k;
            p[ci][cj] = ds[k];
        }
    }

    if (p[bi][bj]) {
        cout << "YES\n";
        string res = "";
        while (ai ^ bi || aj ^ bj) {
            res += p[bi][bj];
            int dd = d[bi][bj] ^ 2;
            bi += dx[dd];
            bj += dy[dd];
        }

        reverse(res.begin(), res.end());
        cout << res.size() << endl;
        cout << res << endl;
    }
    else cout << "NO\n";
}