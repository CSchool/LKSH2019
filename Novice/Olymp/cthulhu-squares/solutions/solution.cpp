#include <iostream>

using namespace std;

int main()
{
    const int limit = 1000;

    for (int i = 1; i < limit + 1; ++i)
        for (int j = 1; j < limit + 1; ++j)
            for (int k = 1; k < limit + 1; ++k)
                if (i * i + j * j == k * k) {
                    cout << i << " " << j << " " << k << endl;
                }

    return 0;
}
