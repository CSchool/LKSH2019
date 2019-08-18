#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unordered_map>

using namespace std;

using ull = unsigned long long;

vector<string> types = {
    "bool",
    "char",
    "signed char",
    "unsigned char",
    "short",
    "signed short",
    "unsigned short",
    "short int",
    "signed short int",
    "unsigned short int",
    "int",
    "signed int",
    "unsigned int",
    "signed",
    "unsigned",
    "long",
    "signed long",
    "unsigned long",
    "long int",
    "signed long int",
    "unsigned long int",
    "long long",
    "signed long long",
    "unsigned long long",
    "long long int",
    "signed long long int",
    "unsigned long long int",
};

unordered_map<string, ull> sizes;

string res;

pair<string, ull> random_type() {
    while (true) {
        auto t = types[rnd.next(types.size())];
        ull mx = 1000000000 / sizes[t];
        ull sz = sizes[t];
        if (mx < 1) continue;
        if (mx > 1000) mx = 1000;
        if (rnd.next(2)) {
            t += '[';
            auto arr = rnd.next(1ull, mx);
            t += to_string(arr);
            t += ']';
            sz *= arr;
        }
        return {t, sz};
    }
}

void generate_struct() {
    string name = rnd.next("[a-zA-Z]{32}");
    res += "typedef ";
    res += name;
    res += " ";
    if (rnd.next(2)) {
        res += "struct {\n";

        int n = rnd.next(1, 100);
        ull s = 0;
        for (int i = 0; i < n; ++i) {
            auto [t, sz] = random_type();
            s += sz;
            res += t;
            res += ";\n";
        }

        res += "}\n";

        types.push_back(name);
        sizes[name] = s;
    } else {
        auto [t, sz] = random_type();
        res += t;
        res += "\n";
        types.push_back(name);
        sizes[name] = sz;
    }
}

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    for (const auto &s : types) sizes[s] = 8;

    int structs = atoi(argv[1]);
    for (int i = 0; i < structs; ++i) generate_struct();
    cout << res;

    for (const string &s : types) {
        cout << "sizeof " << s << '\n';
        cout << "alignof " << s << '\n';
    }

    return 0;
}
