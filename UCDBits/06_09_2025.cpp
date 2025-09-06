#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, x4, x5, x6, x7, x8;
    cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8;

    if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 > 8) {
        cout << "F" << endl;
    } else {
        cout << "S" << endl;
    }
    return 0;
}
