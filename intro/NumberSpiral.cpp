#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t, y, x;
    cin >> t;

    while (t--) {
        cin >> y >> x;
        ll m = max(y, x);
        ll m2 = (m - 1) * (m - 1);

        if (m % 2 == 0) {
            if (m == x)
                cout << m2 + y;
            else
                cout << m2 + 2 * m - x;
        }
        else {
            if (m == x)
                cout << m2 + 2 * m - y;
            else
                cout << m2 + x;
        }

        cout << endl;
    }
}