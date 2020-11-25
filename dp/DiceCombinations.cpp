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

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    a[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(6, i); j++)
            a[i] = (a[i] + a[i - j]) % M;

    cout << a[n] << "\n";
}