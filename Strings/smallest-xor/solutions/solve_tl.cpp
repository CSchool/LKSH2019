#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int ans = 1 << 30;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            ans = std::min(ans, a[i] ^ a[j]);
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
