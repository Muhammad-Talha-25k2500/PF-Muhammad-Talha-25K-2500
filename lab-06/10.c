#include <stdio.h>

int main() {
    int num, position = 1, digit, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (num > 0) {
        digit = num % 10;
        if (position % 2 != 0) {
            sum += digit;
        }
        num /= 10;
        position++;
    }

    printf("Sum of digits in odd positions = %d\n", sum);
    return 0;
}

