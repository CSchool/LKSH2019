#include <bits/stdc++.h>

using namespace std;

const int SIGMA = 26;
int a[SIGMA], b[SIGMA];
string s;
int ans;

int solve(int *a, int *b) {
    int a_sum = 0;
    int b_sum = 0;
    for (char c : s) {
        b_sum += b[c - 'a'];
    }
    int ans = a_sum + b_sum;
    for (char c : s) {
        a_sum += a[c - 'a'];
        b_sum -= b[c - 'a'];
        ans = min(ans, a_sum + b_sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < SIGMA; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < SIGMA; ++i) {
        cin >> b[i];
    }
    cin >> s;

    ans = min(solve(a, b), solve(b, a));

    cout << ans << '\n';
    return 0;
}
