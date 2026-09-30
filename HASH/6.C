#include <stdio.h>
#include <stdlib.h>
#define MAXV 1000005
int main()
{
    int M, Q, N;
    scanf("%d", &M);
    scanf("%d", &Q);
    scanf("%d", &N);
    int *A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int answer = 0;
    /*
       An element A[i] can reach:
       A[i] - Q*M ... A[i] + Q*M
       using steps of M.
    */
    for (int i = 0; i < N; i++) {
        int target = A[i];
        int count = 0;

        for (int j = 0; j < N; j++) {
            int diff = target - A[j];

            if (diff % M == 0 &&
                abs(diff) / M <= Q) {
                count++;
            }
        }

        if (count > answer)
            answer = count;
    }

    printf("%d\n", answer);

    free(A);

    return 0;
}