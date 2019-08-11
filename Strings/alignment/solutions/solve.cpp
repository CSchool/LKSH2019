#include <iostream>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    int size = 0;
    int align = 0;
    for (int i = 0; i < n; ++i) {
        std::string tp, t;
        std::cin >> tp;

        int s = 0, arr = 1;
        auto pos = tp.find('[');
        t = tp.substr(0, pos);

        if (pos != std::string::npos) {
            std::stringstream ss;
            ss << tp.substr(pos + 1);
            ss >> arr;
        }

        if (t == "char") s = 1;
        if (t == "short") s = 2;
        if (t == "int") s = 4;
        if (t == "long") s = 8;

        while (size % s != 0) size++;
        if (s > align) align = s;
        size += s * arr;
    }
    if (align > 0) {
        while (size % align != 0) size++;
    }
    std::cout << size << std::endl;
    std::cout << align << std::endl;
    return 0;
}
