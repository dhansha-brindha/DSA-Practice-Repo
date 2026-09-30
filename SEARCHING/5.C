#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = data;
}

void display() {
    if (front == -1) {
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main() {
    int n, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);
    }

    display();

    return 0;
}