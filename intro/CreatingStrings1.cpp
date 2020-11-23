#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    vector<string> res;
    sort(s.begin(), s.end());
    res.push_back(s);

    while (next_permutation(s.begin(), s.end())) {
        res.push_back(s);
    }

    cout << res.size() << endl;

    for (string st : res)
        cout << st << endl;
}