#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *new_n;
    new_n = (struct node *)malloc(sizeof(struct node));

    new_n->data = data;

    if (front == NULL)
    {
        front = rear = new_n;
        new_n->next = front;
    }
    else
    {
        new_n->next = front;
        rear->next = new_n;
        rear = new_n;
    }
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
        return;

    if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display()
{
    struct node *temp;

    if (front == NULL)
        return;

    temp = front;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

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

    display();

    dequeue();

    display();

    return 0;
}