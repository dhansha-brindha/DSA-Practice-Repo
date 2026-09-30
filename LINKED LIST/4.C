#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int d)
{
    struct node *new_n = (struct node *)malloc(sizeof(struct node));
    new_n->data = d;
    new_n->next = NULL;

    if (rear == NULL)
        front = rear = new_n;
    else
    {
        rear->next = new_n;
        rear = new_n;
    }
}

void dequeue()
{
    if (front == NULL)
        return;

    struct node *temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void print()
{
    struct node *p = front;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int n, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }

    print();
    dequeue();
    print();

    return 0;
}