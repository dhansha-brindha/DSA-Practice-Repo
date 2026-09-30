#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void enqueue(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
void dequeue()
{
    if (front == NULL)
        return;
    struct Node *temp = front;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}
int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    dequeue();
    dequeue();
    while (front != NULL)
    {
        printf("%d ", front->data);
        front = front->next;
    }
    return 0;
}