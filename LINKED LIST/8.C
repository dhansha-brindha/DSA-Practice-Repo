#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int page;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void moveToFront(struct Node *temp)
{
    if (temp == front)
        return;

    if (temp == rear)
        rear = temp->prev;

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->next = front;
    temp->prev = NULL;
    front->prev = temp;
    front = temp;

    if (rear == NULL)
        rear = front;
}

void insert(int page, int capacity, int *size)
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        if (temp->page == page)
        {
            moveToFront(temp);
            return;
        }
        temp = temp->next;
    }

    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->page = page;
    temp->prev = NULL;
    temp->next = front;

    if (front != NULL)
        front->prev = temp;
    else
        rear = temp;

    front = temp;
    (*size)++;

    if (*size > capacity)
    {
        temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        free(temp);
        (*size)--;
    }
}

void display()
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->page);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int capacity, n, page, i;
    int size = 0;

    scanf("%d", &capacity);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &page);
        insert(page, capacity, &size);
        display();
    }

    return 0;
}