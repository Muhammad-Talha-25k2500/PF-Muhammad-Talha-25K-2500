#include <stdio.h>


int main() {
    int n;
    int i, j, spaces;

    printf("Enter an odd number of rows: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    i = 1;
    while (i <= n) {
        spaces = (n - i) / 2;
        j = 1;
        while (j <= spaces) {
            printf(" ");
            j++;
        }
        j = 1;
        while (j <= i) {
            printf("*");
            j++;
        }
        printf("\n");
        i += 2;
    }

    i = n - 2;
    while (i >= 1) {
        spaces = (n - i) / 2;
        j = 1;
        while (j <= spaces) {
            printf(" ");
            j++;
        }
        j = 1;
        while (j <= i) {
            printf("*");
            j++;
        }
        printf("\n");
        i -= 2;
    }

    return 0;
}

*/
/*

#include <stdio.h>

int main() {
    int n;
    int i, j, spaces;

    printf("Enter an odd number of rows: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd number.\n");
        return 1;
    }

    for (i = 1; i <= n; i += 2) {
        spaces = (n - i) / 2;

        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    for (i = n - 2; i >= 1; i -= 2) {
        spaces = (n - i) / 2;

        for (j = 1; j <= spaces; j++) {
            printf(" ");
        }

        for (j = 1; j <= i; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

*/

Both loops produce the same result. However, for loops are more efficient and cleaner when the number of iterations is fixed (like star patterns). while loops are better when you don’t know how many times you’ll loop.

