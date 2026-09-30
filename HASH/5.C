#include <stdio.h>

int main()
{
    char str[1005];
    int freq[256] = {0};

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            freq[(unsigned char)str[i]]++;
    }

    int best = 0;

    for (int i = 1; i < 256; i++) {
        if (freq[i] > freq[best])
            best = i;
    }

    printf("%c %d", best, freq[best]);

    return 0;
}