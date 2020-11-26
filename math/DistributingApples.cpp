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

int main() {
    int n, m;
    cin >> n >> m;

    int max = 2e6 + 1;
    vector<ll> inv(max), f1(max), f2(max);

    inv[1] = 1;
    for (int i = 2; i < max; i++) {
        inv[i] = M - (M / i) * inv[M % i] % M;
    }

    f1[0] = f2[0] = 1;

    for (int i = 1; i < max; i++) {
        f1[i] = f1[i - 1] * i % M;
        f2[i] = f2[i - 1] * inv[i] % M;
    }
    
    cout << f1[n + m - 1] * f2[m] % M * f2[n - 1] % M << endl;
}