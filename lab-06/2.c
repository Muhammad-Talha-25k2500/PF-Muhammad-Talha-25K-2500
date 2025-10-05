#include <stdio.h>

int main(){
	int num, temp, sum=0, i;
	int digit,rev=0,prime=1;
	
	
	printf("enter a 5 digit number: ");
	if (scanf("%d", &num) !=1 || num<10000 || num>99999){
		printf("invalid input, please enter a 5 digit number\n");
		return 1;
	}
	
	temp = num;
    while (temp > 0) {
        digit = temp % 10;
        sum += digit;
        temp = temp / 10;
    }
    
    printf("Sum of digits = %d\n", sum);
    
    
    if (sum % 2 == 0)
        printf("The sum of digits is even.\n");
    else
        printf("The sum of digits is odd.\n");
        
    
    
        if (sum % 2 == 0) {
        if (num <= 1)
            prime = 0;
        else {
            for (i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    prime = 0;
                    break;
                }
            }
        }

        if (prime)
            printf("%d is a prime number.\n", num);
        else
            printf("%d is not a prime number.\n", num);
    }

   
    else {
        temp = num;
        while (temp > 0) {
            rev = rev * 10 + (temp % 10);
            temp = temp / 10;
        }

        if (num == rev)
            printf("%d is a palindrome.\n", num);
        else
            printf("%d is not a palindrome.\n", num);
    }

    return 0;
}

