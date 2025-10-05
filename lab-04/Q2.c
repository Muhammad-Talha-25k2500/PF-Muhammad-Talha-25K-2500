#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;

    printf("Enter first num: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid input for the first num.\n");
        return 1;
    }

    printf("Enter second num: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Invalid input for the second num.\n");
        return 1;
    }

    printf("Enter operator (+, -, *, /): ");
    if (scanf(" %c", &op) != 1) {
        printf("Invalid input for operator.\n");
        return 1;
    }

    switch (op) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %.2f\n", result);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("Result: %.2f\n", result);
            }
            break;
        default:
            printf("Invalid operator. Please use +, -, *, or /.\n");
            break;
    }

    return 0;
}

