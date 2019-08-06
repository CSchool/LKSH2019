#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    cout << n << endl;

    int s = atoi(argv[2]);

    vector<int> res;

    while (res.size() < n) {
        while (res.size() < n) res.push_back(rnd.next(0, ((1 << 30) - 1) / s));
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
    }
    shuffle(res.begin(), res.end());
    for (int i = 0; i < n; ++i) {
        cout << res[i] * s;
        if (i < n - 1) cout << ' ';
    }
    cout << endl;

    return 0;
}
