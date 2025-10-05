#include <stdio.h>


int main(){
	int i;
	long long num;
	long long factorial=1;
	
	
	printf("enter a number: ");
	if (scanf("%11d", &num) !=1||num<0){
		printf("u enterned a invalid input, please enter a positive number :) \n");
		return 1;
	}
	
	for(i= 1;i<=num;i++){
		factorial = factorial * i;
	}
	
	printf("factorial of %11d = %11d \n", num, factorial);
	
	return 0;
}


/*
int main(){
	int num,sum,temp;
	
	printf("enter a 5 digit number please :) : ");
	if (scanf("%d", &num) !=1 || num<10000 || num>99999){
		printf("invalid input, please enter a 5 digit number!! \n");
		return 1;
	}
}
*/
