#include "testlib.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int S = atoi(argv[2]);

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        string t;
        int size, arr = 0;
        if (rnd.next(2)) {
            size = rnd.next(1, S / (n - i));
        } else {
            arr = 1;
            size = rnd.next(1, min(8, S / (n-i)));
        }
        int mt = 0;
        if (size >= 2) mt = 1;
        if (size >= 4) mt = 2;
        if (size >= 8) mt = 3;
        int r = rnd.next(0, mt);
        int s = 0;
        if (r == 0) {
            t = "char";
            s = 1;
        } else if (r == 1) {
            t = "short";
            s = 2;
        } else if (r == 2) {
            t = "int";
            s = 4;
        } else if (r == 3) {
            t = "long";
            s = 8;
        }

        if (!arr) arr = size / s;
        cout << t;
        if ((arr > 1) || rnd.next(2)) {
            cout << '[' << arr << ']';
        }
        cout << endl;
        S -= size;
    }

    return 0;
}
