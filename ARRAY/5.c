#include <stdio.h>

int main()
{
    char nums[13][256] = {
        "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",
        "SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"
    };

    int n, i, j, count[26] = {0}, max[26] = {0};

    while (scanf("%d", &n) && n != 999)
    {
        printf("%d ", n);

        for (j = 0; nums[n][j]; j++)
            count[nums[n][j] - 'A']++;

        for (j = 0; j < 26; j++)
        {
            if (count[j] > max[j])
                max[j] = count[j];
            count[j] = 0;
        }
    }

    printf("999. ");

    for (i = 0; i < 26; i++)
        for (j = 0; j < max[i]; j++)
            printf("%c ", 'A' + i);

    printf("\n");
    printf("CH.SC.U4CSE25265\n");

    return 0;
}