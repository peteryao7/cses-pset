#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int main() {
    string s;
    cin >> s;

    set<int> set;
    string res;

    // if there's a substring with all 4 letters, then pull one letter from it
    // then start looking at the next substring
    for (auto c : s) {
        set.insert(c);
        if (set.size() == 4) {
            res += c;
            set.clear();
        }
    }

    // append one letter that wasn't seen in the last substring
    if (!set.count('A')) res += 'A';
    else if (!set.count('C')) res += 'C';
    else if (!set.count('G')) res += 'G';
    else res += 'T';

    cout << res << endl;
}