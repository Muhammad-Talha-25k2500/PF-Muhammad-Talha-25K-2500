#include <stdio.h>

int main() {
    float level;

    printf("Enter the water level in feet: ");
    if (scanf("%f", &level) != 1 || level<0) {
        printf("Invalid input.\n");
        return 1;
    }

    if (level < 2.0)
        printf("No Relief Required\n");
    else if (level <= 4.0)
        printf("Small Relief Package\n");
    else if (level <= 6.0)
        printf("Medium Relief Package\n");
    else
        printf("Evacuation Required\n");

    return 0;
}

