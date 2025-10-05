#include <stdio.h>

int main(){
	float marks;
	char extra;
	
	printf("input marks out of 100: ");
	if (scanf("%f%c", &marks,&extra) !=2 || extra !='\n'|| marks<0 || marks>100){
		printf("invalid input");
		return 1;
	}
	
	if (marks >= 85 && marks <= 100) {
        printf("Grade: A\n");
    } else if (marks >= 70 && marks <= 84) {
        printf("Grade: B\n");
    } else if (marks >= 55 && marks <= 69) {
        printf("Grade: C\n");
    } else if (marks >= 40 && marks <= 54) {
        printf("Grade: D\n");
    } else if (marks < 40 && marks >= 0){
    	printf("Grade: F\n");
	}
	return 0;
}
