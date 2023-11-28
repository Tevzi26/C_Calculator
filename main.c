#include <stdio.h>
#include <math.h>

void getString(char *string, int size){
	printf("Vnesi racun: ");
	fgets(string, size, stdin);
}


int main(void){
	char string[100];
	getString(string, sizeof(string));

	printf("%s\n", string);


	return 0;
}
