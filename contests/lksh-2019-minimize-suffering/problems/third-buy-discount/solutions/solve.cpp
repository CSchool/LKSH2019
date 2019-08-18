#include <cstdio>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdlib>

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

double minCost( vector <int> prices, int discount ) {
    multiset<int> M( prices.begin(), prices.end() );
    double ret = 0., d = 1.*discount/100.;


    for( int i = 0; M.size(); ++i ) {
        if( i % 3 == 2 ) {
            double a = *M.rbegin();
            M.erase( M.find( *M.rbegin() ) );
            ret += a - d * a;
        } else {
            ret += *M.begin();
            M.erase( M.find( *M.begin() ) );
        }
    }
    return ret;
}

int main()
{
    int n;
    int discount;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
        cin >> prices[i];
    cin >> discount;
    cout.precision(20);
    cout << minCost(prices, discount) << "\n";
}

