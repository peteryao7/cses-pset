#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int res = 1, cur = 0;
    char ch = 'A';

    for (char c : s) {
        if (ch == c) {
            cur++;
            res = max(res, cur);
        }
        else {
            ch = c;
            cur = 1;
        }
    }

    cout << res << endl;
}