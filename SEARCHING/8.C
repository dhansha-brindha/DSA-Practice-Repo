#include <stdio.h>

int main() {
    int n, x;
    int q[100], size = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        int pos = -1;

        for (int j = 0; j < size; j++) {
            if (q[j] == x) {
                pos = j;
                break;
            }
        }

        if (pos != -1) {
            for (int j = pos; j > 0; j--)
                q[j] = q[j - 1];

            q[0] = x;
        } else {
            if (size < 3)
                size++;
            else {
                for (int j = size - 1; j > 0; j--)
                    q[j] = q[j - 1];
            }

            q[0] = x;
        }

        for (int j = 0; j < size; j++)
            printf("%d ", q[j]);

        printf("\n");
    }

    return 0;
}