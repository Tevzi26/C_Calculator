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

void parseString(char *input, double *numbers, char *operators,int *sign, int *nNum, int *nOp){
	*nNum = 0;
	*nOp = 0;

	if(isdigit(input[0]) || input[0] == '+') *sign = 1;
	else if(input[0] == '-') *sign = -1;

	for(int i = 0; input[i]; ++i){
		if (isdigit(input[i]) || input[i] == '.' && isdigit(input[i+1] )) {
			numbers[*nNum] = strtod(input + i, NULL);
			

			while (isdigit(input[i]) || input[i] == '.') ++i;
			--i;

			(*nNum)++;

		} else if(isOperator(input[i]) && i != 0) {
			operators[*nOp] = input[i];

			(*nOp)++;
	        }
	}
}

double operationOrder(char *operators, double *numbers){
	int n = 0;
	double result = 0;

	for(int i = 0; i <= sizeof(operators); ++i){
		if(operators[i] == '*'){
			if(result == 0){
				result = result + numbers[n-1];
			}
			result = multiply(result, numbers[n]);
			
		} else if(operators[i] == '/'){
			if(result == 0){
				result = result + numbers[n];
			}
			printf("%.2f, %.2f\n %d\n", result, numbers[n+1], i);
			result = divide(result, numbers[n+1]);
			
		}
		++n;
	}
	return result;
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

	double numbers[100];
	char operators[100];
	int sign;
	int nNum, nOp;

	parseString(input, numbers, operators, &sign, &nNum, &nOp);

	for (int i = 0; i < nNum; ++i)
		printf("%.2f ", numbers[i]);
		printf("\n");
	for (int i = 0; i < nOp; ++i)
		printf("%c ", operators[i]);
	printf("\n");

	printf("%.2f\n", operationOrder(operators, numbers));
	return 0;
}
