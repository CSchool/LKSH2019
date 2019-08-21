#include "testlib.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    std::vector<std::string> t;

    int q = atoi(argv[1]);
    cout << q << endl;

    for (int i = 0; i < q; ++i) {
        string s = rnd.next("[a-z]{1,15}");
        if (rnd.next(0, 1) && !t.empty()) {
            s = t[rnd.next(t.size())];
        } else {
            t.push_back(s);
        }
        if (rnd.next(0, 1)) {
            cout << "= ";
            cout << s;
            cout << " " << rnd.next(-1000000000, 1000000000);
        } else {
            cout << "? ";
            cout << s;
        }
        cout << endl;
    }

    return 0;
}
