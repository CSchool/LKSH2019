#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>
#include <set>
#include <map>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <ctime>
#include <stack>
#include <cstdlib>
#include <queue>
#include <bitset>

using namespace std;

enum STATE {TEXT, IN_CURLY, PRE_SLASH, IN_LINE, IN_CSTYLE, PRE_STAR};

typedef tuple<STATE, char, STATE, int> Transition;

vector<Transition> trans = {
        make_tuple(TEXT, '{', IN_CURLY, 0),
        make_tuple(PRE_SLASH, '{', IN_CURLY, -'/'),
        make_tuple(IN_CURLY, '}', TEXT, 0),
        make_tuple(TEXT, '/', PRE_SLASH, 0),
        make_tuple(PRE_SLASH, '/', IN_LINE, 0),
        make_tuple(IN_LINE, '\n', TEXT, 1),
        make_tuple(PRE_SLASH, '*', IN_CSTYLE, 0),
        make_tuple(IN_CSTYLE, '*', PRE_STAR, 0),
        make_tuple(PRE_STAR, '*', PRE_STAR, 0),
        make_tuple(PRE_STAR, '/', TEXT, 0),
        make_tuple(TEXT, 0, TEXT, 1),
        make_tuple(PRE_STAR, 0, IN_CSTYLE, 0),
        make_tuple(IN_CSTYLE, 0, IN_CSTYLE, 0),
        make_tuple(IN_LINE, 0, IN_LINE, 0),
        make_tuple(IN_CURLY, 0, IN_CURLY, 0),
        make_tuple(PRE_SLASH, 0, TEXT, '/')
};

int main()
{
    string s, line;
    while (getline(cin, line))
        s += line + "\n";

    STATE st = TEXT;

    for (char c : s)
    {
        for (Transition tr : trans)
        {
            if ((get<0>(tr) == st) &&
                ((get<1>(tr) == c) || (get<1>(tr) == 0)))
            {
                st = get<2>(tr);
                if (get<3>(tr) > 0)
                {
                    if (get<3>(tr) >= 32)
                        cout << static_cast<char>(get<3>(tr));
                    cout << c;
                }

                if (get<3>(tr) < 0)
                {
                    cout << static_cast<char>(-get<3>(tr));
                }
                break;
            }
        }
    }

    return 0;
}
