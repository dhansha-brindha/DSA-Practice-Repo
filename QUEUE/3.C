#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = 0, rear = -1;
void enqueue(int data)
{
    if (rear == MAX - 1)
        return;

    queue[++rear] = data;
}
void dequeue()
{
    if (front > rear)
        return;

    front++;
}
int main()
{
    int n, data, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }
    dequeue();
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    return 0;
}