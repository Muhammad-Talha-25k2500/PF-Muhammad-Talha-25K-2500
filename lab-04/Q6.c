#include <stdio.h>

int main(){
	int num1,num2,num3;
	char extra;
	
	printf("enter integers: ");
	if (scanf("%d%d%d%c", &num1,&num2,&num3,&extra) !=4 || extra !='\n'){
		printf("invalid input");
		return 1;
	}
	
	if (num1>num2 && num1>num3){
	printf("num1 is the largest");
	}	else if (num2>num1 && num2>num3){
	printf("num2 is the largest");
	}
	else printf("num3 is the largest");
	
	return 0;
	
}
