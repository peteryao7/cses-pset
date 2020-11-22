#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    int child[n];

    for (int i = 0; i < n; i++)
        cin >> child[i];

    sort(child, child + n);

    int i = 0, j = n - 1;
    int res = 0;

    while (i < j) {
        if (child[i] + child[j] > x) {
            res++;
            j--;
        }
        else {
            res++;
            i++, j--;
        }
    }
    cout << res << endl;
}