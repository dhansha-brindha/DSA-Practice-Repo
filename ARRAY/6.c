#include <stdio.h>

#define MAX 10
#define LEN 100

int main()
{
    int afford[MAX], price[MAX];
    char name[MAX][LEN];
    int money, items, i, bought = 0;

    scanf("%d %d", &money, &items);

    for(i=0;i<items;i++)
        scanf("%s %d", name[i], &price[i]);

    for(i=0;i<items;i++)
    {
        if(price[i] <= money)
        {
            printf("I can afford %s\n", name[i]);
            money -= price[i];
            bought++;
        }
        else
            printf("I can't afford %s\n", name[i]);
    }

    if(bought == 0)
        printf("I need more Dollar!\n");
    else
        printf("%d\n", money);

    printf("CH.SC.U4CSE25265\n");

    return 0;
}