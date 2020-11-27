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

string s;
bool visited[7][7];
int res;

bool valid(int i, int j) {
    return i >= 0 && i < 7 && j >= 0 && j < 7 && !visited[i][j];
}

// backtrack + dfs
void dfs(int i, int j, int pathLen) {
    if (i == 6 && j == 0) {
        if (pathLen == 48)
            res++;
        return;
    }
    
    visited[i][j] = 1;

    if (s[pathLen] == '?' || s[pathLen] == 'L') {
        // if left cell is valid and not visited
        if (j > 0 && !visited[i][j - 1]) {
            // if you reach the left edge and the up/down cells are unvisited
            // then the board is split in two halves and a path is now impossible
            if(!(!valid(i, j - 2) && valid(i + 1, j - 1) && valid(i - 1, j - 1)))
                dfs(i, j - 1, pathLen + 1);
        }
    }

    if (s[pathLen] == '?' || s[pathLen] == 'R') {
        if (j < 6 && !visited[i][j + 1]) {
            if(!(!valid(i, j + 2) && valid(i + 1, j + 1) && valid(i - 1, j + 1)))
                dfs(i, j + 1, pathLen + 1);
        }
    }

    if (s[pathLen] == '?' || s[pathLen] == 'U') {
        if (i > 0 && !visited[i - 1][j]) {
            if(!(!valid(i - 2, j) && valid(i - 1, j + 1) && valid(i - 1, j - 1)))
                dfs(i - 1, j, pathLen + 1);
        }
    }

    if (s[pathLen] == '?' || s[pathLen] == 'D') {
        if (i < 6 && !visited[i + 1][j]) {
            if(!(!valid(i + 2, j) && valid(i + 1, j + 1) && valid(i + 1, j - 1)))
                dfs(i + 1, j, pathLen + 1);
        }
    }

    visited[i][j] = 0;
}

int main() {
    cin >> s;
    dfs(0, 0, 0);
    cout << res << endl;
}