#define ll long long
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<set>
#include<cassert>

using namespace std;

const int N = 100010;

string st, a;
int n, m, k, g[N][30];
bool term[N];

bool go()
{
	int pos = 0;
	for (int i = 0; i < st.size(); i++)
	{
		if (g[pos][st[i] - 'a'] > -1)
			pos = g[pos][st[i] - 'a'];
		else
			return false;
	}
	return term[pos];
}

int main()
{
	getline(cin, st);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		term[i] = 0;
		for (int j = 0; j < 30; j++)
			g[i][j] = -1;
	}
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		term[x - 1] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		char c;
		cin >> x >> y >> c;
		g[x - 1][c - 'a'] = y - 1;
	}
	if (go())
		cout << "Accepts";
	else
		cout << "Rejects";
	return 0;
}
