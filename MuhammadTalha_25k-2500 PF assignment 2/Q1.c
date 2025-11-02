#include <stdio.h>
#include <string.h>

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count);
void processSale(int isbns[], int quantities[], int count);
void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);
int findBookByISBN(int isbns[], int count, int isbn);

int main() {
    int isbns[100];
    char titles[100][50];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        printf("\n===== Liberty Books Inventory System =====\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(isbns, titles, prices, quantities, &count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting... Thank you for using Liberty Books System!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

int findBookByISBN(int isbns[], int count, int isbn) {
    for (int i = 0; i < count; i++) {
        if (isbns[i] == isbn)
            return i;
    }
    return -1;
}

void addBook(int isbns[], char titles[][50], float prices[], int quantities[], int *count) {
    if (*count >= 100) {
        printf("Inventory full! Cannot add more books.\n");
        return;
    }

    int isbn;
    printf("\nEnter ISBN: ");
    scanf("%d", &isbn);

    if (findBookByISBN(isbns, *count, isbn) != -1) {
        printf("Error: Book with this ISBN already exists!\n");
        return;
    }

    isbns[*count] = isbn;

    printf("Enter Title: ");
    getchar();
    fgets(titles[*count], 50, stdin);
    titles[*count][strcspn(titles[*count], "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &prices[*count]);

    printf("Enter Quantity: ");
    scanf("%d", &quantities[*count]);

    (*count)++;

    printf("Book added successfully!\n");
}

void processSale(int isbns[], int quantities[], int count) {
    int isbn, copies;
    printf("\nEnter ISBN of book to sell: ");
    scanf("%d", &isbn);

    int index = findBookByISBN(isbns, count, isbn);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }

    printf("Enter number of copies sold: ");
    scanf("%d", &copies);

    if (copies > quantities[index]) {
        printf("Error: Not enough stock! Available: %d\n", quantities[index]);
    } else {
        quantities[index] -= copies;
        printf("Sale processed! Remaining stock: %d\n", quantities[index]);
    }
}

void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    printf("\n===== Low Stock Report (Quantity < 5) =====\n");
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: Rs. %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found)
        printf("All books are sufficiently stocked.\n");
}

