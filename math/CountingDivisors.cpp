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
const int M = 1e9 + 7;

int main() {
    int max = 1e6 + 1;
    vi factors(max);

    // sieve
    for (int i = 1; i < max; i++) {
        for (int j = i; j < max; j += i)
            factors[j]++;
    }

    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cout << factors[x] << endl;
    }
}