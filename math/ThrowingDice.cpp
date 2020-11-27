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

void mult(ll a[6][6], ll b[6][6], ll cc[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            ll c = 0;

            for (int k = 0; k < 6; k++)
                c = (c + (ll) a[i][k] * b[k][j]) % M;
                
            cc[i][j] = c;
        }
    }
}

// modular expo
void pow(ll a[6][6], ll p[6][6], ll t[6][6], ll k) {
    if (k == 0) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                p[i][j] = (i == j);
            }
        }
        return;
    }

    if (k & 1) {
        pow(a, p, t, k / 2);
        mult(p, p, t);
        mult(t, a, p);
    }
    else {
        pow(a, t, p, k / 2);
        mult(t, t, p);
    }
}

int main() { 
    ll n;
    cin >> n;

    // general case - CSES pg 221
    ll a[6][6] = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
    };
    ll p[6][6], t[6][6];

    pow(a, p, t, n);
    cout << p[5][5] << endl;
}