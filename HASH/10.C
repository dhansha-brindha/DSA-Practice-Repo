#include <stdio.h>

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);

    long long freq[M];

    for (int i = 0; i < M; i++)
        freq[i] = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        scanf("%lld", &x);

        freq[x % M]++;
    }

    long long answer = 0;

    for (int a = 0; a < M; a++) {
        for (int b = a; b < M; b++) {

            int c = (M - (a + b) % M) % M;

            if (c < b || c >= M)
                continue;

            if (a == b && b == c) {
                answer += freq[a] *
                          (freq[a] - 1) *
                          (freq[a] - 2) / 6;
            }
            else if (a == b) {
                answer += freq[a] *
                          (freq[a] - 1) / 2 *
                          freq[c];
            }
            else if (b == c) {
                answer += freq[b] *
                          (freq[b] - 1) / 2 *
                          freq[a];
            }
            else {
                answer += freq[a] *
                          freq[b] *
                          freq[c];
            }
        }
    }

    printf("%lld\n", answer);

    return 0;
}