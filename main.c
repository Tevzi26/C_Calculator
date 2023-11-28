#include <stdio.h>
#include <string.h>
#include <math.h>

void getString(char *string, int size){
	printf("Vnesi racun: ");
	fgets(string, size, stdin);

	int lenght = strlen(string);

	if (lenght > 0 && string[lenght-1] == '\n') string[lenght-1] = '\0';
}

int handleSum(char *string, int size){
	int sum = 0;
	for (int i = 0; i < size; i++){
		if (string[i] >= '0' && string[i] <= '9' && i < 1){
			sum = string[i] - '0';
		}else if (string[i] == '+'){
			sum = sum + string[i+1] - '0';
		}
	}
	return sum;
}


int main(void){
	char string[100];
	getString(string, sizeof(string));

	printf("%s\n", string);
	int sum = handleSum(string, strlen(string));
	printf("%d\n", sum);


	return 0;
}
