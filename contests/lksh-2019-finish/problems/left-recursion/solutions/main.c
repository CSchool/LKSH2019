#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);
    int r = 0;
    while (n--)
    {
        char s[50];
        fgets(s, sizeof(s), stdin);
        r += s[0] == s[3];
    }
    printf("%d\n", r);
}
