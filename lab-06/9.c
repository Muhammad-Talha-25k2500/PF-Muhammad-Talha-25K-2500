#include <stdio.h>

int main() {
    int number, temp, divisor = 1, digit, count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    temp = number;

    while (temp >= 10) {
        temp = temp / 10;
        divisor = divisor * 10;
    }

    printf("\nDigits in order:\n");

    do {
        digit = number / divisor;          
        count++;
        printf("Digit %d: %d\n", count, digit);
        number = number % divisor;
        divisor = divisor / 10;
    } while (divisor > 0);

    return 0;
}

