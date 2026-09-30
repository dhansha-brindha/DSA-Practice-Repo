#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int data;
    struct Queue *next;
};
void enQueue(struct Queue **front, struct Queue **rear, int value)
{
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = value;
    if (*front == NULL)
    {
        *front = *rear = newNode;
        newNode->next = *front;
    }
    else
    {
        newNode->next = *front;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}
int deQueue(struct Queue **front, struct Queue **rear)
{
    if (*front == NULL)
        return -1;
    int value = (*front)->data;
    if (*front == *rear)
    {
        free(*front);
        *front = *rear = NULL;
    }
    else
    {
        struct Queue *temp = *front;
        *front = (*front)->next;
        (*rear)->next = *front;
        free(temp);
    }
    return value;
}
void displayQueue(struct Queue *front)
{
    if (front == NULL)
        return;
    struct Queue *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}
int main()
{
    struct Queue *front = NULL;
    struct Queue *rear = NULL;
    int n, i, value;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enQueue(&front, &rear, value);
    }
    displayQueue(front);
    deQueue(&front, &rear);
    deQueue(&front, &rear);
    displayQueue(front);
    return 0;
}