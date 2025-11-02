#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void toggleBits(char *ch);
void reverseString(char str[]);

int main(){
    int choice;
    char message[500];

    do{
        printf("\n=== TCS Secure Message Utility ===\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1:
                printf("\nEnter the message to ENCODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';

                encodeMessage(message);
                break;

            case 2:
                printf("\nEnter the message to DECODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';

                decodeMessage(message);
                break;

            case 3:
                printf("\nExiting program... Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select again.\n");
        }

    } while (choice != 3);

    return 0;
}

void encodeMessage(char message[]){
    reverseString(message);

    for (int i = 0; message[i] != '\0'; i++){
        toggleBits(&message[i]);
    }

    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[]){
    for (int i = 0; message[i] != '\0'; i++){
        toggleBits(&message[i]);
    }

    reverseString(message);

    printf("\nDecoded Message: %s\n", message);
}

void toggleBits(char *ch){
    *ch ^= (1 << 1);
    *ch ^= (1 << 4);
}

void reverseString(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
