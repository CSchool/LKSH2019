#include <stdio.h>
#include <stdlib.h>

char s[25][10];
int n;

int check(int x, int y, int z)
{
    for (int i = 0 ; i < n ; ++i)
    {
        char *p = s[i];
        int left = 0, right = 0;
        if (p[0] == 'x')
            left = x;
        else if (p[0] == 'y')
            left = y;
        else if (p[0] == 'z')
            left = z;

        if (p[4] == 'x')
            right = x;
        else if (p[4] == 'y')
            right = y;
        else if (p[4] == 'z')
            right = z;
        else
            right = atoi(p + 4);

        int res = 0;
        if (p[2] == '>')
            res = left > right;
        else
            res = left < right;
        if (!res)
            return 0;
    }
    return 1;
}

int main()
{
    scanf("%d\n", &n);
    for (int i = 0 ; i < n ; ++i)
        fgets(s[i], 10, stdin);
    int res = 0;
    for (int x = 0 ; x <= 100 ; ++x)
        for (int y = 0 ; y <= 100 ; ++y)
            for (int z = 0 ; z <= 100 ; ++z)
            {
                if (check(x, y, z))
                    ++res;
            }
    printf("%d\n", res);
}
