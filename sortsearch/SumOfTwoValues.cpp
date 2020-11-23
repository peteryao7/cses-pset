#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;

    map<int, int> map;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (map.find(x - a) != map.end()) {
            cout << map[x - a] + 1 << " " << i + 1 << endl;
            return 0;
        }
        map[a] = i;
    }

    cout << "IMPOSSIBLE\n";
}