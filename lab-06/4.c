#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char username[20], password[20];
    char login_user[20], login_pass[20];
    int i, valid, upper, lower, digit;

    // --- USERNAME ---
    while (1) {
        printf("Enter username (5 alphabets): ");
        scanf("%s", username);

        if (strlen(username) != 5) {
            printf("? Username must be 5 letters long.\n");
            continue;
        }

        valid = 1;
        for (i = 0; i < 5; i++) {
            if (!isalpha(username[i])) {
                printf(" Username should only have alphabets.\n");
                valid = 0;
                break;
            }
        }

        if (!valid) continue;
        break; // username valid
    }

    // --- PASSWORD ---
    while (1) {
        printf("Enter password (6 chars, must have upper, lower, digit): ");
        scanf("%s", password);

        if (strlen(password) != 6) {
            printf(" Password must be 6 characters long.\n");
            continue;
        }

        upper = lower = digit = 0;

        for (i = 0; i < 6; i++) {
            if (isupper(password[i])) upper = 1;
            if (islower(password[i])) lower = 1;
            if (isdigit(password[i])) digit = 1;
        }

        if (!(upper && lower && digit)) {
            printf("? Must include uppercase, lowercase, and number.\n");
            continue;
        }

        break; // password valid
    }

    printf("\n? Account Created Successfully!\n");

    // --- LOGIN ---
    while (1) {
        printf("\nLogin Username: ");
        scanf("%s", login_user);
        printf("Login Password: ");
        scanf("%s", login_pass);

        if (strcmp(username, login_user) == 0 && strcmp(password, login_pass) == 0) {
            printf("\n Welcome %s, you are now logged in.\n", username);
            break;
        } else {
            printf(" Incorrect username or password. Try again.\n");
            continue;
        }
    }

    return 0;
}

