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

int isOperator(char c){
	return(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

void parseString(char *input, double *numbers, char *operators, int *nNum, int *nOp){
	*nNum = 0;
	*nOp = 0;

	for(int i = 0; input[i]; ++i){
		if (isdigit(input[i]) || input[i] == '.' && isdigit(input[i+1] )) {
			numbers[*nNum] = strtod(input + i, NULL);
			

			while (isdigit(input[i]) || input[i] == '.') ++i;
			--i;

			(*nNum)++;

		} else if(isOperator(input[i])) {
			operators[*nOp] = input[i];

			(*nOp)++;
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

	double numbers[10];
	char operators[10];
	int nNum, nOp;

	parseString(input, numbers, operators, &nNum, &nOp);

	printf("Expression 1:\n");
	for (int i = 0; i < nNum; ++i)
		printf("%.2f ", numbers[i]);
		printf("\n");
	for (int i = 0; i < nOp; ++i)
		printf("%c ", operators[i]);
	printf("\n");
	return 0;
}
