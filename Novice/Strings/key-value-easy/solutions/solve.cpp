#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int q;
    std::cin >> q;
    std::unordered_map<std::string, int> m;
    for (int i = 0; i < q; ++i) {
        char c;
        std::cin >> c;
        std::string s;
        std::cin >> s;
        if (c == '=') {
            int x;
            std::cin >> x;
            m[s] = x;
        } else {
            std::cout << m[s] << std::endl;
        }
    }
    return 0;
}
