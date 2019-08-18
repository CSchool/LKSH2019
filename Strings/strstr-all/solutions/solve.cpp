#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    std::string s = b;
    s += '$';
    s += a;

    int n = s.size();
    std::vector<int> p(n);

    for (int i = 1; i < n; ++i) {
        int z = p[i - 1];
        while (z > 0 && (s[z] != s[i])) {
            z = p[z - 1];
        }
        if (s[i] == s[z]) ++z;
        p[i] = z;
    }

    int m = b.size();

    bool first = true;

    for (int i = m + 1; i < n; ++i) {
        if (p[i] == m) {
            if (!first) std::cout << ' ';
            first = false;
            std::cout << i - 2 * m;
        }
    }
    std::cout << std::endl;
    return 0;
}
