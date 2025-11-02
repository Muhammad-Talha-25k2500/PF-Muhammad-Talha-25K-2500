#include <stdio.h>
#include <string.h>

int productCodes[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
int stock[] = {50, 10, 20, 8, 15, 30, 12, 25, 18, 40};
float price[] = {100, 200, 300, 150, 80, 120, 250, 60, 400, 180};
int numProducts = 10;

int cartCodes[50];
int cartQty[50];
int cartCount = 0;

char customerName[50];
char customerCNIC[20];

void getCustomerInfo();
void displayInventory();
void addToCart();
void updateInventory(int code, int quantity);
void displayTotalBill();
void showInvoice();
float calculateTotal();

void getCustomerInfo(){
    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", customerName);
    printf("Enter Customer CNIC: ");
    scanf(" %[^\n]", customerCNIC);
    printf("\nCustomer information saved successfully!\n");
}

void displayInventory(){
    printf("\n%-15s %-20s %-20s\n", "Product Code", "Quantity in Stock", "Price per Product");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < numProducts; i++){
        printf("%-15d %-20d Rs.%-17.2f\n", productCodes[i], stock[i], price[i]);
    }
}

void updateInventory(int code, int quantity){
    for (int i = 0; i < numProducts; i++){
        if (productCodes[i] == code){
            stock[i] -= quantity;
            return;
        }
    }
}

void addToCart(){
    int code, quantity, found = 0;

    printf("\nEnter Product Code to add: ");
    scanf("%d", &code);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < numProducts; i++){
        if (productCodes[i] == code){
            found = 1;
            if (quantity <= stock[i]){
                cartCodes[cartCount] = code;
                cartQty[cartCount] = quantity;
                cartCount++;
                updateInventory(code, quantity);
                printf("\nItem added to cart successfully!\n");
            } else{
                printf("\nInsufficient stock! Only %d available.\n", stock[i]);
            }
            break;
        }
    }
    if (!found){
        printf("\nInvalid product code!\n");
    }
}

float calculateTotal(){
    float total = 0;
    for (int i = 0; i < cartCount; i++){
        for (int j = 0; j < numProducts; j++){
            if (cartCodes[i] == productCodes[j]){
                total += cartQty[i] * price[j];
            }
        }
    }
    return total;
}

void displayTotalBill(){
    float total = calculateTotal();
    printf("\n==============================\n");
    printf("Total Bill (Before Discount): Rs. %.2f\n", total);
    printf("==============================\n");
}

void showInvoice(){
    float total = calculateTotal();
    char promo[20];
    float discount = 0, finalAmount = total;

    printf("\nDo you have a promocode? (yes/no): ");
    char ans[10];
    scanf("%s", ans);

    if (strcmp(ans, "yes") == 0){
        printf("Enter promocode: ");
        scanf("%s", promo);
        if (strcmp(promo, "Eid2025") == 0){
            discount = total * 0.25;
            finalAmount = total - discount;
            printf("\nPromocode applied successfully! (25%% OFF)\n");
        } else{
            printf("\nInvalid promocode! No discount applied.\n");
        }
    }

    printf("\n=========== INVOICE ===========\n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %s\n", customerCNIC);
    printf("-------------------------------\n");
    printf("Product Code   Quantity   Price\n");
    printf("-------------------------------\n");

    for (int i = 0; i < cartCount; i++){
        for (int j = 0; j < numProducts; j++){
            if (cartCodes[i] == productCodes[j]){
                printf("%-14d %-10d Rs.%.2f\n", cartCodes[i], cartQty[i], cartQty[i] * price[j]);
            }
        }
    }

    printf("-------------------------------\n");
    printf("Total (No Discount): Rs. %.2f\n", total);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Bill: Rs. %.2f\n", finalAmount);
    printf("===============================\n");
}

int main(){
    int choice;
    do{
        printf("\n========== Supermarket Menu ==========\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice (Checkout)\n");
        printf("6. Exit System\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                getCustomerInfo();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addToCart();
                break;
            case 4:
                displayTotalBill();
                break;
            case 5:
                showInvoice();
                break;
            case 6:
                printf("\nExiting the system. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

