#include <stdio.h>

int main() {
    int totalRows, row, space, num;

    printf("Enter number of rows: ");
    scanf("%d", &totalRows);

    for (row = 1; row <= totalRows; row++) {

        for (space = 1; space <= totalRows - row; space++) {
            printf(" ");
        }

        for (num = 1; num <= row; num++) {
            printf("%d", num);
        }

        for (num = row - 1; num >= 1; num--) {
            printf("%d", num);
        }

        printf("\n");
    }

    return 0;
}

