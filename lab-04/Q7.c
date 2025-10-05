#include <stdio.h>

int main(){
	int Eunits;
	int bill;
	char extra;
	
	printf("input ur units: ");
	if (scanf("%d%c", &Eunits, &extra) !=2 || extra !='\n'|| Eunits<0){
		printf("invalid input");
		return 1;
	}
	
if (Eunits <= 100) {
        bill = 10 * Eunits;
    } else if (Eunits > 100 && Eunits < 300) {
        bill = 15 * Eunits;
    } else if (Eunits >= 300 && Eunits < 500) {
        bill = 20 * Eunits;
    } else {
        bill = 25 * Eunits;
    }
	
	printf("Your bill is %d\n" ,bill );

} 
