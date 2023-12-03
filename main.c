#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

void parseString(char *input){
	for(int i = 0; input[i]; i++){
		if (isdigit(input[i])) {
			int num = atoi(input + i);
			printf("%d ", num);

			while (isdigit(input[i])) ++i;
			--i;

		} else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')') {
			printf("%c ", input[i]);
	        }
	}
}

void getString(char *string, int size){
	printf("Vnesi izraz: ");
	fgets(string, size, stdin);

	int lenght = strlen(string);

	if(lenght > 0 && string[lenght-1] == '\n') string[lenght-1] = '\0';
}

int main(void){
	char input[100];
	getString(input, sizeof(input));

	printf("%s\n%d\n", input, strlen(input));
	parseString(input);


	return 0;
}
