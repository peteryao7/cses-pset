#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    ll a[n], sum = 0, res = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // loop over bitmask
    // more info: https://stackoverflow.com/questions/41028859/looping-over-a-bitmask
    for (int i = 0; i < 1 << n; i++) {
        ll csum = 0;

        for (int j = 0; j < n; j++) {
            if ((1 << j) & i)
                csum += a[j];
        }

        if (csum <= sum / 2)
            res = max(res, csum);
    }

    cout << (sum - res) - res << endl;
}