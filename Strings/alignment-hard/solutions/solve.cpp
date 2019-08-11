#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using ull = unsigned long long;

std::vector<std::string> tokens;
std::unordered_map<std::string, ull> size, align;
ull ptr = 0;

std::string read_token() {
    return tokens[ptr++];
}

std::string next_token() {
    if (ptr < tokens.size())
        return tokens[ptr];
    return "";
}

void skip_suff() {
    auto s = next_token();
    if (s == "int" || s == "long") {
        read_token();
        skip_suff();
    }
}

std::string read_primitive() {
    auto s = read_token();
    if (s == "struct") {
        read_token();
        return "struct";
    }
    if (s == "unsigned" || s == "signed") {
        auto next = next_token();
        if (next == "short" || next == "int" || next == "char" || next == "long") {
            return read_primitive();
        }
        return "int";
    }
    if (s == "short" || s == "long") {
        skip_suff();
    }
    return s;
}

std::pair<std::string, ull> read_type() {
    ull x = 1;
    auto t = read_primitive();
    if (t == "struct") return {t, 0};
    auto arr = next_token();
    if (!arr.empty() && arr[0] == '[') {
        std::stringstream ss;
        ss << arr.substr(1);
        ss >> x;
        read_token();
    }
    return {t, x};
}

int main() {
    size["bool"] = align["bool"] = 1;
    size["char"] = align["char"] = 1;
    size["short"] = align["short"] = 2;
    size["int"] = align["int"] = 4;
    size["long"] = align["long"] = 8;
    std::string s;
    while (std::cin >> s) {
        auto pos = s.find(';');
        bool semicolon = false;
        if (pos != std::string::npos) {
            s = s.substr(0, s.size() - 1);
            semicolon = true;
        }
        pos = s.find('[');
        if (pos != std::string::npos) {
            auto arr = s.substr(pos);
            s = s.substr(0, pos);
            tokens.push_back(s);
            tokens.push_back(arr);
        } else {
            tokens.push_back(s);
        }
        if (semicolon) tokens.push_back(";");
    }

    while (ptr < tokens.size()) {
        auto cmd = read_token();
        if (cmd == "typedef") {
            auto t = read_primitive();
            auto [x, arr] = read_type();
            if (x == "struct") {
                ull S = 0, A = 0;
                while (next_token() != "}") {
                    auto [y, a] = read_type();
                    read_token(); // skip semicolon
                    ull q = size[y] * a;
                    ull al = align[y];
                    while (S % al != 0) S++;
                    if (A < al) A = al;
                    S += q;
                }
                while (S % A != 0) S++;
                read_token();
                size[t] = S;
                align[t] = A;
            } else {
                size[t] = size[x] * arr;
                align[t] = align[x];
            }
        }
        if (cmd == "sizeof") {
            auto [t, arr] = read_type();
            std::cout << size[t] * arr << std::endl;
        }
        if (cmd == "alignof") {
            auto [t, arr] = read_type();
            std::cout << align[t] << std::endl;
        }
    }
    return 0;
}
