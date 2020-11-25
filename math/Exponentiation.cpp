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

// modular exponentiation
// x^n = 1 if n = 0
//       x^(n/2) * x^(n/2) if n even
//       x^(n-1) * x if n odd
ll modpow(ll base, ll exp) {
    ll res = 1;
    
    while (exp) {
        if (exp & 1)
            res = res * base % M;

        base = base * base % M;
        exp /= 2;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;

        cout << modpow(a, b) << endl;
    }
}