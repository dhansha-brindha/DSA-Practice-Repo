#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enQueue(int value) {
    if ((rear + 1) % MAX == front)
        return;

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

int deQueue() {
    int value;

    if (front == -1)
        return -1;

    value = queue[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return value;
}

void displayQueue() {
    int i;

    if (front == -1)
        return;

    i = front;

    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enQueue(x);
    }

    printf("Elements in Circular Queue are:");
    displayQueue();
    printf("\n");

    x = deQueue();
    printf("Deleted value = %d", x);

    return 0;
}