#include <stdio.h>

int main() {
    char sentence[100];
    int index, wordEnd, wordStart;

    printf("Enter a sentence: ");
    gets(sentence);

    for (wordEnd = 0; sentence[wordEnd] != '\0'; wordEnd++);

    printf("Reversed sentence: ");

    index = wordEnd - 1;
    while (index >= 0) {
        while (index >= 0 && sentence[index] == ' ')
            index--;

        if (index < 0)
            break;

        wordStart = index;
        while (wordStart >= 0 && sentence[wordStart] != ' ')
            wordStart--;

        int printPos = wordStart + 1;
        while (printPos <= index) {
            printf("%c", sentence[printPos]);
            printPos++;
        }

        if (wordStart >= 0)
            printf(" ");

        index = wordStart - 1;
    }

    printf("\n");
    return 0;
    
}

