#include <stdio.h>
#include <string.h>

int a[255] = {
 ['0'] = 0x001,
 ['1'] = 0x002,
 ['2'] = 0x004,
 ['3'] = 0x008,
 ['4'] = 0x010,
 ['5'] = 0x020,
 ['6'] = 0x040,
 ['7'] = 0x080,
 ['8'] = 0x100,
 ['9'] = 0x200,
 ['a'] = 0x00f,
 ['b'] = 0x01e,
 ['c'] = 0x03c,
 ['d'] = 0x078,
 ['e'] = 0x0f0,
 ['f'] = 0x1e0,
 ['g'] = 0x3c0,
 ['?'] = 0x3ff,
};

int bitcount(int c)
{
	int r = 0;
	while (c)
	{
		r += c & 1;
		c >>= 1;
	}
	return r;
}

int main()
{
	char p1[10], p2[10];
	fgets(p1, sizeof(p1), stdin);
	fgets(p2, sizeof(p2), stdin);
	size_t len = strlen(p1);
	long long answer = 1;
	for (size_t i = 0 ; i < len - 1 ; ++i)
	{
		int m = a[p1[i]] & a[p2[i]];
		if (m == 0)
			answer = 0;
		answer *= bitcount(m);
	}
	printf("%lld\n", answer);
}
