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

void mult(ll a[2][2], ll b[2][2], ll cc[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ll c = 0;

            for (int k = 0; k < 2; k++)
                c = (c + (ll) a[i][k] * b[k][j]) % M;
                
            cc[i][j] = c;
        }
    }
}

// modular expo
void pow(ll a[2][2], ll p[2][2], ll t[2][2], ll k) {
    // [f(n+1)   f(n)]
    // [f(n)   f(n-1)]
    if (k == 0) {
        p[0][0] = 1; p[0][1] = 0;
        p[1][0] = 0; p[1][1] = 1;
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

    ll a[2][2] = {{0, 1}, {1, 1}};
    ll p[2][2], t[2][2];

    pow(a, p, t, n);
    cout << p[1][0] << endl;
}