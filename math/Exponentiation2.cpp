#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

ll modpow(ll base, ll exp, int mod) {
    ll res = 1;
    
    while (exp) {
        if (exp & 1)
            res = res * base % mod;

        base = base * base % mod;
        exp /= 2;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Fermat's theorem (CSES pg 202)
        cout << modpow(a, modpow(b, c, M - 1), M) << endl;
    }
}