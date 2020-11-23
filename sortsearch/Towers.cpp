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
    ll n, k;
    cin >> n;
    multiset<int> s;

    while (n--) {
        cin >> k;
        auto it =  s.lower_bound(k + 1);
        if (it == s.end())
            s.insert(k);
        else {
            s.erase(it);
            s.insert(k);
        }
    }

    cout << s.size() << endl;
}