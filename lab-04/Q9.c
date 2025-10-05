#include <stdio.h>

int main() {
    float rainfall, riverFlow;

    printf("Enter rainfall (mm): ");
    if (scanf("%f", &rainfall) != 1 || rainfall < 0) {
        printf("Invalid input for rainfall.\n");
        return 1;
    }

    printf("Enter river flow (m^3/s): ");
    if (scanf("%f", &riverFlow) != 1 || riverFlow < 0) {
        printf("Invalid input for river flow.\n");
        return 1;
    }

    if (rainfall < 50 && riverFlow < 200) {
        printf("Risk Level: Low Risk\n");
    } 
    else if (rainfall >= 50 && rainfall <= 100 && riverFlow >= 200 && riverFlow <= 500) {
        printf("Risk Level: Moderate Risk\n");
    } 
    else if (rainfall > 100 && rainfall <= 150 && riverFlow > 500 && riverFlow <= 800) {
        printf("Risk Level: High Risk\n");
    } 
    else if (rainfall > 150 && riverFlow > 800) {
        printf("Risk Level: Severe Risk - Evacuate!\n");
    } 
    else {
        printf("Risk Level: Data does not fit standard risk categories.\n");
    }

    return 0;
}

