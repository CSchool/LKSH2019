#include <iostream>
using namespace std;

int main() {
    long n;
    long a[102];
    long b;

    cin >> n >> a[1];
    a[0] = 0;

    if (n < 2) {
        cout << a[1] << endl;
        return 0;
    }

    for (int i = 2; i <= n; ++i) {
        cin >> b;
        a[i] = max(a[i - 1], a[i - 2]) + b;
    }

    cout << a[n] << endl;
    return 0;
}
