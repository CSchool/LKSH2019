#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long int a = 0;
    cin >> a;

    if (a == 2) {
        cout << "2" << endl;
        return 0;
    }

    for (int number = 2; number < a; ++ number) {
        bool isPrime = true;
        double limit = ceil(sqrt(number)) + 1;
        for (long int divider = 2; divider < limit; ++divider) {
            if (number % divider == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << number << " ";
        }
    }

    return 0;
}
