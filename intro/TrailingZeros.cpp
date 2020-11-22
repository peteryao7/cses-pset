#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    ll res = 0;
    
    for (int i = 5; n / i >= 1; i *= 5)
        res += n / i;

    cout << res << endl;
}