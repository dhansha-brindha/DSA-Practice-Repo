#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *rear = NULL;
void enqueue(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    if (rear == NULL)
    {
        rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue()
{
    if (rear == NULL)
        return;
    struct Node *front = rear->next;
    if (front == rear)
        rear = NULL;
    else
        rear->next = front->next;

    free(front);
}
void display()
{
    if (rear == NULL)
        return;
    struct Node *temp = rear->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
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
    display();
    return 0;
}