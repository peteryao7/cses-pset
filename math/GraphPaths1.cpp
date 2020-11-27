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

const int N = 100;

void mult(ll a[N][N], ll b[N][N], ll cc[N][N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = 0;

            for (int k = 0; k < n; k++)
                c = (c + (ll) a[i][k] * b[k][j]) % M;
                
            cc[i][j] = c;
        }
    }
}

// modular expo
void pow(ll a[N][N], ll p[N][N], ll t[N][N], int n, int k) {
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j] = (i == j);
            }
        }
        return;
    }

    if (k & 1) {
        pow(a, p, t, n, k / 2);
        mult(p, p, t, n);
        mult(t, a, p, n);
    }
    else {
        pow(a, t, p, n, k / 2);
        mult(t, t, p, n);
    }
}

int main() { 
    int n, m, k;
    cin >> n >> m >> k;
    ll a[N][N], p[N][N], t[N][N];

    while (m--) {
        int i, j;
        cin >> i >> j;
        a[--i][--j]++; 
    }

    pow(a, p, t, n, k);
    cout << p[0][n - 1] << endl;
}