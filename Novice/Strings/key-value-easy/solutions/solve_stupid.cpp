#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<std::string, int>> v;

    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        std::string s;
        std::cin >> s;
        auto it = std::find_if(v.begin(), v.end(),
                [&](std::pair<std::string, int> p) {
                    return p.first == s;
            });

        if (c == '=') {
            int x;
            std::cin >> x;
            if (it == v.end()) {
                v.emplace_back(s, x);
            } else {
                it->second = x;
            }
        } else {
            if (it == v.end()) {
                std::cout << 0 << std::endl;
            } else {
                std::cout << it->second << std::endl;
            }
        }
    }
    return 0;
}
