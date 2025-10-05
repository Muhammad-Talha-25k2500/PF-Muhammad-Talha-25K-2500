#include <stdio.h>

int main(){
	int num;
	char extra;
	
	printf("Input a integer:");
	if (scanf("%d%c", &num,&extra) !=2 || extra != '\n'){
		printf("invlaid input");
		return 1;
	}
	
	if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }
	return 0;
}
