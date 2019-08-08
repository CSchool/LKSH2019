#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int m;
    std::cin >> m;
    while (m--) {
        int t;
        std::cin >> t;
        auto it = std::lower_bound(a.begin(), a.end(), t);
        if (it != a.end() && *it == t) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
