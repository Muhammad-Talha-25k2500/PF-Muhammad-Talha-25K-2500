#include <stdio.h>

#define POWER_ON        1   // 0001 -> Bit 0
#define OVERLOAD        2   // 0010 -> Bit 1
#define MAINTENANCE     4   // 0100 -> Bit 2

void updateSectorStatus(int grid[10][10], int rows, int cols);
void querySectorStatus(int grid[10][10], int rows, int cols);
void runSystemDiagnostic(int grid[10][10], int rows, int cols);

void setFlag(int *sector, int flag);
void clearFlag(int *sector, int flag);
int checkFlag(int sector, int flag);

int main(){
    int rows, cols;
    printf("Enter number of rows in grid: ");
    scanf("%d", &rows);
    printf("Enter number of columns in grid: ");
    scanf("%d", &cols);

    int grid[10][10] = {0};
    int choice;

    do{
        printf("\n====== IESCO Power Grid Monitoring System ======\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                updateSectorStatus(grid, rows, cols);
                break;
            case 2:
                querySectorStatus(grid, rows, cols);
                break;
            case 3:
                runSystemDiagnostic(grid, rows, cols);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

void setFlag(int *sector, int flag){
    *sector |= flag;
}

void clearFlag(int *sector, int flag){
    *sector &= ~flag;
}

int checkFlag(int sector, int flag){
    return (sector & flag) != 0;
}

void updateSectorStatus(int grid[10][10], int rows, int cols){
    int r, c, flagChoice, action;
    printf("\nEnter Sector Coordinates (row col): ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols){
        printf("Invalid coordinates!\n");
        return;
    }

    printf("Select Status Flag to Update:\n");
    printf("1. Power Status\n");
    printf("2. Overload Warning\n");
    printf("3. Maintenance Required\n");
    printf("Enter choice: ");
    scanf("%d", &flagChoice);

    int flag;
    switch (flagChoice){
        case 1: flag = POWER_ON; break;
        case 2: flag = OVERLOAD; break;
        case 3: flag = MAINTENANCE; break;
        default: printf("Invalid flag!\n"); return;
    }

    printf("Enter 1 to SET or 0 to CLEAR the flag: ");
    scanf("%d", &action);

    if (action == 1)
        setFlag(&grid[r][c], flag);
    else
        clearFlag(&grid[r][c], flag);

    printf("Status updated successfully for sector [%d][%d]!\n", r, c);
}

void querySectorStatus(int grid[10][10], int rows, int cols){
    int r, c;
    printf("\nEnter Sector Coordinates (row col): ");
    scanf("%d %d", &r, &c);

    if (r < 0 || r >= rows || c < 0 || c >= cols){
        printf("Invalid coordinates!\n");
        return;
    }

    int sector = grid[r][c];
    printf("\n--- Sector [%d][%d] Status Report ---\n", r, c);
    printf("Power: %s\n", checkFlag(sector, POWER_ON) ? "ON" : "OFF");
    printf("Overload: %s\n", checkFlag(sector, OVERLOAD) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", checkFlag(sector, MAINTENANCE) ? "YES" : "NO");
}

void runSystemDiagnostic(int grid[10][10], int rows, int cols){
    int overloaded = 0, maintenance = 0;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (checkFlag(grid[i][j], OVERLOAD))
                overloaded++;
            if (checkFlag(grid[i][j], MAINTENANCE))
                maintenance++;
        }
    }

    printf("\n===== SYSTEM DIAGNOSTIC REPORT =====\n");
    printf("Total sectors overloaded: %d\n", overloaded);
    printf("Total sectors requiring maintenance: %d\n", maintenance);
    printf("====================================\n");
}

