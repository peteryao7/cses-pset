#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    int ch[26] = {};
    int odds = 0;

    for (char c : s)
        ch[c - 'A']++;

    for (int i : ch) {
        if (i % 2)
            odds++;
    }

    if (odds > 1) {
        cout << "NO SOLUTION";
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        if (ch[i] % 2 == 0) {
            for (int j = 0; j < ch[i] / 2; j++) {
                cout << (char) ('A' + i);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (ch[i] % 2) {
            for (int j = 0; j < ch[i]; j++) {
                cout << (char) ('A' + i);
            }
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (ch[i] % 2 == 0) {
            for (int j = 0; j < ch[i] / 2; j++) {
                cout << (char) ('A' + i);
            }
        }
    }

    cout << endl;
}