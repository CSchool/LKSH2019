#include <stdio.h>
#include <string.h>

char s[100001];

int main()
{
    fgets(s, sizeof(s), stdin);
    int res = 0;
    int len = strlen(s);
    if (s[len - 1] == '\n')
        --len;
    while (len > 1)
    {
        int next = 1;
        for (int i = 0 ; next && i < (len + 1) / 2 ; ++i)
            if (s[i] != s[len - 1 - i])
                next = 0;
        if (!next)
            break;
        ++res;
        len = (len + 1) / 2;
    }
    printf("%d\n", res);
}
