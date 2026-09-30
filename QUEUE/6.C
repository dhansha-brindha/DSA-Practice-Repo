#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int data)
{
    if ((rear + 1) % MAX == front)
        return;

    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}
void dequeue()
{
    if (front == -1)
        return;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}
int main()
{
    int n, data;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }
    dequeue();
    for (int i = front; i != rear; i = (i + 1) % MAX)
        printf("%d ", queue[i]);
    if (front != -1)
        printf("%d", queue[rear]);

    return 0;
}