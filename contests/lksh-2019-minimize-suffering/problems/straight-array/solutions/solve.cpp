#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int howManyMore( vector <int> nums ) {
    sort( nums.begin(), nums.end() );
    nums.resize( unique( nums.begin(), nums.end() ) - nums.begin() );

    set< int > pq( nums.begin(), nums.end() );

    int sol = 5;
    vector< int > V = nums;
    int n = V.size();

    for( int i = 0; i < n; ++i ) {
        int tmp = 5;

        for( int j = V[i]; j < V[i]+5; ++j )
            tmp -= pq.count( j );

        sol = min(sol, tmp);
    }

    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << howManyMore(a);
    return 0;
}
