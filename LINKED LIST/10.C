#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (front == -1)
        front = 0;

    queue[++rear] = data;
}

void reverse()
{
    int i, j, temp;

    for (i = front, j = rear; i < j; i++, j--)
    {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

void display()
{
    int i;

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}

int main()
{
    int n, i, data;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(data);
    }

    printf("Queue:");
    display();

    reverse();

    printf("Reversed Queue:");
    display();

    return 0;
}