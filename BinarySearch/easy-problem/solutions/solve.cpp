#include <iostream>

using namespace std;

int main()
{
    int i, x, y, ans, n;
    cin >> n >> x >> y;
    int l = -1, r = 2e9 + 1, m;
    while(l != r - 1)
    {
        m = l + (r - l) / 2;
        if((m / x + m / y) >= n - 1)
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r + min(x, y);
    return 0;
}
