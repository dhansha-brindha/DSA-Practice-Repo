#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int item) {
    struct node* temp =
        (struct node*)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = temp->right = NULL;

    return temp;
}

struct node* insert(struct node* root, int item) {
    if (root == NULL)
        return newNode(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);

    return root;
}

void postorder(struct node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n, x;
    struct node* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    postorder(root);

    return 0;
}