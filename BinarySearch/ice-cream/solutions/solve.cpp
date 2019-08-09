#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

const int MAXN = 100000;
const int MAXC = 1000000000;

int n, k;
int a[MAXN];

void Load()
{
	scanf("%d%d", &n, &k);
	int i;
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
}

bool Can(int md)
{
	int cnt = 1;
	int i = 0;
	int prev = 0;
	while (i < n && cnt < k)
	{
		if (a[i] - a[prev] >= md)
		{
			cnt++;
			prev = i;
		}
		else
		{
			i++;
		}
	}
	return (cnt == k);
}

void Solve()
{
	sort(a, a + n);
	int l = 0;
	int r = MAXC;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (Can(m))
		{
			if (m > ans) ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	printf("%d\n", ans);
}

int main()
{
	Load();
	Solve();
	return 0;
}
