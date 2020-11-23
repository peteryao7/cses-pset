#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    array<int, 2> movies[n];

    for (int i = 0; i < n; i++) {
        cin >> movies[i][1] >> movies[i][0];
    }

    // sort end times
    sort(movies, movies + n);

    int res = 0, prev = 0;

    for (int i = 0; i < n; i++) {
        if (movies[i][1] >= prev) {
            res++;
            prev = movies[i][0];
        }
    }

    cout << res << endl;
}