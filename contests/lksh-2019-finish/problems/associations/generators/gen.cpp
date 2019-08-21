#include "testlib.h"
#include <iostream>
#include <cstdlib>

using namespace std;

const int MIN_N = 2;
const int MAX_N = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int M = atoi(argv[2]);

    cout << n << endl;

    vector<string> assoc(M);
    for (int i = 0; i < M; i++) {
        assoc[i] = rnd.next("[a-z]{1,10}");
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << assoc[rnd.next(0, M - 1)] << endl;
        }
    }



    return 0;
}
