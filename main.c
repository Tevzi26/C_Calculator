#include <stdio.h>
#include <string.h>
#include <math.h>

double add(double a, double b){
	return a+b;
}

double subtract(double a, double b){
	return a-b;
}

double multiply(double a, double b){
	return a*b;
}

double divide(double a, double b){
	if (b != 0){
		return a/b;
	}
	else {
		printf("error");
	}
}

void getType(char *input, int *isNum, int lenght){
	
	for (int i = 0; i < lenght; i++){
		if (input[i] <= '9' && input[i] >= '0'){
			isNum[i] = 1;
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*'){
			isNum[i] = 0;
		}
		else{
			isNum[i] = -1;
		}
	}
}

void getString(char *string, int size){
	printf("Vnesi izraz: ");
	fgets(string, size, stdin);

	int lenght = strlen(string);

	if (lenght > 0 && string[lenght-1] == '\n') string[lenght-1] = '\0';
}

int main(void){
	char input[100];
	getString(input, sizeof(input));
	
	int n = strlen(input);
	double num;
	int tab[n];
	getType(input, tab, n);

	printf("%s\n%d\n", input, strlen(input));
	for (int i = 0; i < n; i++){
		printf("%d\n", tab[i]);
	}


	return 0;
}
