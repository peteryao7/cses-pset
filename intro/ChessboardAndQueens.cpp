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

string s[8];
vi queenPos;
ll res;

void backtrack(int i) {
    if (i == 8) {
        res++;
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (s[i][j] == '*')
            continue;

        bool valid = true;

        for (int k = 0; k < i; k++) {
            if (queenPos[k] == j || queenPos[k] == j + (i - k) || queenPos[k] == j - (i - k)) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        queenPos.push_back(j);
        backtrack(i + 1);
        queenPos.pop_back();
    }
}

// backtracking
int main() {
    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }

    backtrack(0);
    cout << res << endl;
}