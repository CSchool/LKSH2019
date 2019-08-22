#include <iostream>
#include <vector>

using namespace std;

vector<string> a[111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            a[i].push_back(s);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cur = 0;
            for (int t = 0; t < 3; t++) {
                bool ok = false;
                for (int v = 0; v < 3; v++) {
                    if (a[i][t] == a[j][v]) {
                        ok = true;
                    }
                }
                if (ok) {
                    cur++;
                }
            }
            ans = max(ans, cur);
        }
    }

    cout << ans;


    return 0;
}
