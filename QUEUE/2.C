#include <stdio.h>
#include <string.h>
int main()
{
    char s[200005];
    int n, m, x;
    scanf("%s", s);
    n = strlen(s);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &x);
        // Flip the bit
        if (s[x - 1] == '0')
            s[x - 1] = '1';
        else
            s[x - 1] = '0';
        // Find longest consecutive substring
        int maxLen = 1;
        int curr = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                curr++;
            else
                curr = 1;

            if (curr > maxLen)
                maxLen = curr;
        }
        printf("%d ", maxLen);
    }
    return 0;
}