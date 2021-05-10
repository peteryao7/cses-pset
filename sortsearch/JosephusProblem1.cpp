#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vi c(n);
    for (int i = 1; i <= n; i++) {
        c[i - 1] = i;
    }

    while (c.size() > 1) {
        vi cc;
        for (int i = 0; i < c.size(); i++) {
            if (i % 2 == 1)
                cout << c[i] << " ";
            else
                cc.push_back(c[i]);
        }
        if (c.size() % 2 == 1) {
            int last = cc.back();
            cc.pop_back();
            cc.insert(cc.begin(), last);
        }
        c = cc;
    }

    cout << c[0] << endl;
}