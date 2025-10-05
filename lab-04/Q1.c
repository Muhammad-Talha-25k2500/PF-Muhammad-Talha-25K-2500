#include <stdio.h>

int main() {
    int num;
    char extra;

    printf("Enter an integer: ");
    if (scanf("%d%c", &num, &extra) != 2 || extra != '\n') {
        printf("Invalid input. Please enter a whole num.\n");
        return 1;
    }

    if (num > 0) printf("%d, The num is Positive.\n", num);
    else if (num < 0) printf("%d, The num is Negative.\n", num);
    else printf("The num is Zero.\n");

    return 0;
}

