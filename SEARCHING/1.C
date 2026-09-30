#include <stdio.h>
#include <string.h>

int main() {
    char var[3][10];
    double val[3], M = 0, D = 0, X = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%s %lf", var[i], &val[i]);

        if (var[i][0] == 'M') M = val[i];
        else if (var[i][0] == 'D') D = val[i];
        else if (var[i][0] == 'X') X = val[i];
    }

    if (var[0][0] == 'X' || var[1][0] == 'X' || var[2][0] == 'X') {
        X = -M / D;
        printf("x %.2f\n", X);
    } else if (var[0][0] == 'M' || var[1][0] == 'M' || var[2][0] == 'M') {
        M = -D * X;
        printf("M %.2f\n", M);
    } else {
        D = -M / X;
        printf("D %.2f\n", D);
    }

    return 0;
}