#include <stdio.h>

int main() {
    float akhlaq, honesty, prayer, fasting, zakat, social, conflict;
    float CI;

    printf("Enter score for Akhlaq & Manners (0-10): ");
    if (scanf("%f", &akhlaq) != 1 || akhlaq < 0 || akhlaq > 10) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Honesty & Trustworthiness (0-10): ");
    if (scanf("%f", &honesty) != 1 || honesty < 0 || honesty > 10) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Prayer Regularity (0=Irregular, 1=Regular): ");
    if (scanf("%f", &prayer) != 1 || (prayer != 0 && prayer != 1)) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Fasting (0=Never, 1=Sometimes, 2=Always): ");
    if (scanf("%f", &fasting) != 1 || fasting < 0 || fasting > 2) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Zakat & Charity (0-10): ");
    if (scanf("%f", &zakat) != 1 || zakat < 0 || zakat > 10) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Social Behavior (0-10): ");
    if (scanf("%f", &social) != 1 || social < 0 || social > 10) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter score for Conflict Resolution Skills (0-10): ");
    if (scanf("%f", &conflict) != 1 || conflict < 0 || conflict > 10) {
        printf("Invalid input!\n");
        return 1;
    }

    
    CI = (akhlaq * 2.5) + (honesty * 2.0) + (prayer * 15) +
         (fasting * 5) + (zakat * 1.0) + (social * 1.0) + (conflict * 1.0);

    printf("\nCharacter Index (CI) = %.2f\n", CI);

    if (CI >= 85 && CI <= 100) {
        printf("Classification: Excellent Muslim Character ?\n");
        printf("Remarks: Role model for society\n");
    }
    else if (CI >= 70 && CI <= 84) {
        printf("Classification: Good Muslim Character ?\n");
        printf("Remarks: Practicing believer\n");
    }
    else if (CI >= 50 && CI <= 69) {
        printf("Classification: Average Character ?\n");
        printf("Remarks: Needs minor improvement\n");
    }
    else if (CI >= 30 && CI <= 49) {
        printf("Classification: Needs Improvement !\n");
        printf("Remarks: Work on Akhlaq & Ibadah\n");
    }
    else {
        printf("Classification: Weak Character ?\n");
        printf("Remarks: Requires serious guidance\n");
    }

    return 0;
}

