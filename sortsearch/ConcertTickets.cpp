#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    set<array<int, 2>> set;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        set.insert({h, i});
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        // first ticket seen above max price
        auto it = set.lower_bound({t + 1, 0});

        if (it == set.begin()) {
            cout << "-1\n";
        }
        else {
            // set upper_bound iterates over prices in sorted order
            // go back one for the latest <=t ticket
            it--;
            cout << (*it)[0] << endl;
            set.erase(it);
        }
    }
}