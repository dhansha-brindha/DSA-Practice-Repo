#include <stdio.h>
#include <string.h>

int main() {
    char s[200005];
    int m, x;

    scanf("%s", s);
    scanf("%d", &m);

    while (m--) {
        scanf("%d", &x);
        x--;

        s[x] = (s[x] == '0') ? '1' : '0';

        int max = 1, count = 1;
        int n = strlen(s);

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;

            if (count > max)
                max = count;
        }

        printf("%d ", max);
    }

    return 0;
}