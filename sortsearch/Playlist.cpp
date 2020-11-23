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
    int p[n];

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int res = 0;
    set<int> set;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && set.find(p[j]) == set.end()) {
            set.insert(p[j]);
            j++;
        }

        res = max(res, j - i);
        set.erase(p[i]);
    }

    cout << res << endl;
}