#include <stdio.h>

int queue[100];
int front = -1, rear = -1;

void enqueue(int data) {
    if (front == -1)
        front = 0;

    queue[++rear] = data;
}

void reverse() {
    int i, j, temp;

    for (i = front, j = rear; i < j; i++, j--) {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

void display() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    printf("Queue:");
    display();

    reverse();

    printf("\nReversed Queue:");
    display();

    return 0;
}