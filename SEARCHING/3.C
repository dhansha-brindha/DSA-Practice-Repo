#include <stdio.h>

int main() {
    int n, a[100], front = 0, rear;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    rear = n - 1;

    while (front <= rear) {
        printf("%d", a[front++]);
        if (front <= rear)
            printf(" ");
    }

    return 0;
}