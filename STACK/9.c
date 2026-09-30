#include <stdio.h>
#include <string.h>

int main()
{
    char s[100], stack[100][100];
    int top = -1;

    scanf("%s", s);

    for (int i = 0; s[i]; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z'))
        {
            stack[++top][0] = s[i];
            stack[top][1] = '\0';
        }
        else
        {
            char a[100], b[100];

            strcpy(a, stack[top--]);
            strcpy(b, stack[top--]);

            sprintf(stack[++top], "%c%s%s", s[i], b, a);
        }
    }

    printf("%s", stack[top]);

    return 0;
}