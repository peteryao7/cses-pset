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
typedef vector<ll> vll;
const int M = 1e9 + 7;

string grid[1000];
int n, m;

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '.';
}

void dfs(int i, int j) {
    grid[i][j] = '#';

    if (valid(i - 1, j))
        dfs(i - 1, j);
    if (valid(i + 1, j))
        dfs(i + 1, j);
    if (valid(i, j - 1))
        dfs(i, j - 1);
    if (valid(i, j + 1))
        dfs(i, j + 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                dfs(i, j);
                res++;
            }
        }
    }

    cout << res << endl;
}