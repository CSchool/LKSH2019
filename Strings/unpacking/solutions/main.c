#include <stdio.h>
#include <ctype.h>

char sym;
int count;
int line;

void unpack()
{
	while (count)
	{
		putc(sym, stdout);
		--count;
		if (++line == 40)
		{
			putc('\n', stdout);
			line = 0;
		}
	}
}

int main()
{
	int c;
	while (isalnum(c = getc(stdin)))
	{
		if (isdigit(c))
		{
			count = count * 10 + c - '0';
		}
		else
		{
			if (!count)
				count = 1;
			sym = c;
			unpack();
		}
	}
	putc('\n', stdout);
}
