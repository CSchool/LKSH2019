#include "testlib.h"
#include <iostream>
using namespace std;

int main()
{
	registerValidation();
	int n = inf.readInt(3,100000);
	inf.readSpace();
	inf.readInt(2,n - 1);
	inf.readEoln();
	int l = -1, c;
	for (int i = 0; i < n; i++)
	{
		c = inf.readInt(0,1000000000);
		ensure (c > l);
		l = c;
		if (i + 1 < n) inf.readSpace();
	}
	inf.readEoln();
	inf.readEof();
	return 0;
}
