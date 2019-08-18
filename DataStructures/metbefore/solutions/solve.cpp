#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> s;
    int n;
    while (std::cin >> n) {
        if (s.find(n) == s.end()) {
            std::cout << "NO\n";
            s.insert(n);
        } else {
            std::cout << "YES\n";
        }
    }
    return 0;
}
