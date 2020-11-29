#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int M = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    int res[n];
    array<int, 3> times[n]; // end, start, original idx
    for (int i = 0; i < n; i++) {
        cin >> times[i][1] >> times[i][0];
        times[i][2] = i;
    }

    sort(times, times + n);
    set<array<int, 2>> s; // end, original idx
    int movies = 0;

    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound({times[i][1] + 1});

        // need a new room
        if (it != s.begin()) {
            it--;
            res[times[i][2]] = (*it)[1];
            s.erase(it);
        }
        // can put person in an occupied room
        else {
            res[times[i][2]] = s.size();
        }
        if (s.size() < k) {
            s.insert({times[i][0], res[times[i][2]]});
            movies++;
        }
    }

    cout << movies << endl;
}