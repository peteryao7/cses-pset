#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

// proof: https://math.stackexchange.com/questions/3266470/divide-the-numbers-1-2-n-into-two-sets-of-equal-sum
int main() {
    ll n;
    cin >> n;

    // can't make 2 equal groups summing to an odd number
    if (n * (n + 1) / 2 % 2) {
        cout << "NO\n";
        return 0;
    }

    vector<int> v1, v2;
    int off = n % 4 ? 3 : 4; // only 0, 3 mod 4 sums work

    for (int i = 0; i < (n - 1) / 4; i++) {
        // 1 + 4 = 2 + 3
        // same offsets
        v1.push_back(4 * i + 1 + off);
        v1.push_back(4 * i + 4 + off);
        v2.push_back(4 * i + 2 + off);
        v2.push_back(4 * i + 3 + off);
    }

    if (n % 4) {
        v1.push_back(1);
        v1.push_back(2);
        v2.push_back(3);
    }
    else {
        v1.push_back(1);
        v1.push_back(4);
        v2.push_back(2);
        v2.push_back(3);
    }

    cout << "YES\n";
    cout << v1.size() << endl;
    for (int i : v1)
        cout << i << ' ';
    cout << endl;
    cout << v2.size() << endl;
    for (int i : v2)
        cout << i << ' ';
    cout << endl;
}