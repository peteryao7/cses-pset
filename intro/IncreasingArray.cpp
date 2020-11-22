#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll n, temp;
    cin >> n;
    cin >> temp;
    ll res = 0;

    for (int i = 1; i < n; i++) {
        ll cur;
        cin >> cur;
        res += max((ll) 0, temp - cur);
        temp = cur + max((ll) 0, temp - cur);
    }

    cout << res << endl;
}