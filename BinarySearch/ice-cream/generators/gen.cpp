#include "random.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
using namespace std ;

int main (int argc , char *argv[])
{
	if (argc != 5)
	{
		printf ("%s <randseed> <n> <k> <maxval>", argv[0]) ;
		return 0 ;
	}
	initrand(atoi(argv[1])) ;
	int n = atoi(argv[2]) , k = atoi(argv[3]) , mval = atoi(argv[4]) ;
	if (k == -1) k = R(2, n - 1) ;
	printf ("%d %d\n", n, k) ;
	set <int> was ;
	vector <int> res;
	for (int i = 0; i < n; i++)
	{
		int x = rndInt(mval) ;
		while (was.count(x)) x = rndInt(mval) ;
		was.insert (x) ;
		res.push_back(x);
	}
	sort (res.begin(), res.end());
	for (int i = 0; i < n; i++)
	{
		if (i > 0) cout << " ";
		cout << res[i] ;
	}
	cout << endl;
	return 0 ;
}
