#include <stdio.h>
#include <stdbool.h>

long long readtime()
{
	long long t[3] = {0};
	int n = 0;
	do {
		int c = getc(stdin);
		if (c == '\n')
			break;
		if (c == ':')
			++n;
		else
			t[n] = 10 * t[n] + c - '0';
	} while (true);
	long long r = 0;
	for (int i = 0 ; i <= n ; ++i)
		r = r * 60 + t[i];
	return r;
}

int main()
{
	long long t = readtime() + readtime();
	const int d = 60 * 60 * 24;
	long long days = t / d;
	t %= d;
	int h = t / 60 / 60;
	t %= 60 * 60;
	int m = t / 60;
	int s = t % 60;
	printf("%02d:%02d:%02d", h, m, s);
	if (days)
		printf("+%lld days", days);
	printf("\n");
}
