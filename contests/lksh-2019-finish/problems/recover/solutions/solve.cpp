#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

const int MOD = 1000000000 + 7;

int a[2][10010];

int main()
{
	int n;
	string s;
	cin >> s;
	n = s.length();

	memset(a, 0, sizeof(a));
	a[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int cur = i%2, next = (i+1)%2;
		memset(a[next], 0, sizeof(a[next]));
		switch (s[i])
		{
			case '(': 	for (int j = 0; j <= n; ++j)
							a[next][j+1] = a[cur][j];
						break;
			case ')': 	for (int j = 1; j <= n; ++j)
							a[next][j-1] = a[cur][j];
						break;
			case '?': 	for (int j = 0; j <= n; ++j)
							a[next][j+1] = a[cur][j];
						for (int j = 1; j <= n; ++j)
							a[next][j-1] = (a[next][j-1] + a[cur][j]) % MOD;
						break;
		}
	}
	cout << a[n%2][0] << '\n';
	return 0;
}
