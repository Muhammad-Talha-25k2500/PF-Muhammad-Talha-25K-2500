#include <stdio.h>

int main() {
    int number, originalNumber, remainder, result = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    originalNumber = number;

    while (number != 0) {
        remainder = number % 10;
        result = result + (remainder * remainder * remainder);
        number = number / 10;
    }

    if (result == originalNumber)
        printf("%d is an Armstrong number.\n", originalNumber);
    else
        printf("%d is not an Armstrong number.\n", originalNumber);

    return 0;
}

