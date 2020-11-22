#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int apts[n], ppl[m];
    for (int i = 0; i < n; i++)
        cin >> apts[i];
    for (int j = 0; j < m; j++)
        cin >> ppl[j];

    sort(apts, apts + n);
    sort(ppl, ppl + m);

    int res = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && ppl[j] < apts[i] - k)
            j++;
        if (j < m && ppl[j] <= apts[i] + k) {
            res++;
            j++;
        }
    }

    cout << res << endl;
}