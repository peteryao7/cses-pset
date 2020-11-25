#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    int x[n], nl[n];

    for (int i = 0; i < n; i++) {
        cin >> x[i];

        nl[i] = i - 1;

        while (~nl[i] && x[nl[i]] >= x[i]) {
            nl[i] = nl[nl[i]];
        }

        cout << nl[i] + 1 << " ";
    }
}