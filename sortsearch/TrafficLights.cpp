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
    int x, n;
    cin >> x >> n;

    int lights[n];
    set<int> s; // light idx
    multiset<int> m; // ranges

    s.insert(0);
    s.insert(x);

    for (int i = 1; i <= n; i++) {
        cin >> lights[i];

        // find 2 lights next to lights[i]
        auto it = s.lower_bound(lights[i]);
        int r = *it;
        it--;
        int l = *it;
        
        // delete old range
        auto range = m.find(r - l);
        if (range != m.end())
            m.erase(m.find(r - l));

        // add new ranges to m and light idx to s
        m.insert(lights[i] - l);
        m.insert(r - lights[i]);
        s.insert(lights[i]);
        cout << *--m.end() << ' ';
    }
    cout << endl;
}