#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    set<int> s;

    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cout << s.size() << endl;
}