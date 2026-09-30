#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *newNode =
        (struct node *)malloc(sizeof(struct node));

    newNode->data = data;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    int data;
    struct node *temp;

    if (front == NULL)
        return -1;

    data = front->data;

    if (front == rear) {
        free(front);
        front = rear = NULL;
    } else {
        temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }

    return data;
}

void display() {
    struct node *temp;

    if (front == NULL)
        return;

    temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    dequeue();
    dequeue();

    display();

    return 0;
}