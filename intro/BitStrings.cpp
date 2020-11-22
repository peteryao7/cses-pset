#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    int res = 1;

    for (int i = 0; i < n; i++)
        res = 2 * res % ((int) 1e9 + 7);

    cout << res << endl;
}