#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0;
int rear = -1;
void enqueue(int data)
{
    if (rear == MAX - 1)
        return;
    rear++;
    queue[rear] = data;
}
int main()
{
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
        printf("Enqueuing %d\n", data);
        for (int j = front; j <= rear; j++)
        {
            printf("%d ", queue[j]);
        }
        printf("\n");
    }
    return 0;
}
