#include <stdio.h>

int main() {
    int n, i, j, count = 0;
    long long fibTri[1000];  

    printf("Enter number of rows: ");
    scanf("%d", &n);

    fibTri[0] = 1;
    fibTri[1] = 1;
    for (i = 2; i < 1000; i++) {
        fibTri[i] = fibTri[i - 1] + fibTri[i - 2];
    }

    count = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%lld ", fibTri[count]);
            count++;
        }
        printf("\n");
    }

    return 0;
}

