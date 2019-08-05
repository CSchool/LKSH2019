#include <stdio.h>
#include <ctype.h>

int a[256];

int main()
{
	int c;
	int min = 200;
	int max = 0;
	while (isalpha(c = getc(stdin)))
		++a[c];
	for (int i = 'a' ; i <= 'z' ; ++i)
	{
		if (a[i] && a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	printf("%d\n", max - min);
}
