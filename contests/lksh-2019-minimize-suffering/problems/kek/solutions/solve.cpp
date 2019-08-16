#include <algorithm>
#include <functional>

#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#define FORC(it,v) for( __typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it )

int count( string text ) {
    string S = text;
    int len = S.size();

    int bio[ 100 ];
    memset( bio, 0, sizeof bio );

    for( int i = 0; i < len; ++i )
        if( S.substr( i, 3 ) == "kek" )
            bio[i] = bio[i+1] = bio[i+2] = true;

    int sum = 0;
    for( int i = 0; i < len; ++i )
        sum += bio[i];

    return sum;
}

int main() {
  string s;
  getline(cin, s);
  cerr << s << endl;
  cout << count(s) << endl;
}
