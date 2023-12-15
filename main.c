#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define PI 3.1415

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

double power(double a, double b){
	return pow(a, b);
}

int isOperator(char c){
	return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void parseString(char *input, double *numbers, char *operators, char *func, double *sign, int *nNum, int *nOp){
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
	        } else if(input[i] == 's' && input[i+1] == 'i' && input[i+2] == 'n'){
			func[*nOp] = input[i];
			i = i+2;

		} else if(input[i] == 'c' && input[i+1] == 'o' && input[i+2] == 's'){
			func[*nOp] = input[i];
			i = i+2;
		} else if(input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n'){
			func[*nOp] = input[i];
			i = i+2;
		}else if(input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'g'){
			func[*nOp] = input[i];
			i = i+2;
		}
	}
}

void func(char *func, double *numbers, int nNum){
	for(int i = 0; i <= nNum; ++i){
		if(func[i] == 's'){
			numbers[i] = sin(numbers[i] * (PI / 180));
		} else if(func[i] == 'c'){
			numbers[i] = cos(numbers[i] * (PI / 180));
		} else if(func[i] == 's'){
			numbers[i] = tan(numbers[i] * (PI / 180)); //TODO: error handling
		} else if(func[i] == 'l'){
			numbers[i] = log(numbers[i]);
		}
	}
}

double operationOrder(char *operators, double *numbers, double *sign, char *func, int nOp){
	double result = 0;
	if(!func[0])  
		numbers[0] = *sign * numbers[0];
	//numbers[0] = 1;

	for(int i = 0; i <= sizeof(operators); ++i){
		if(operators[i] == '-'){
			numbers[i+1] = numbers[i+1] * -1;
			
		}
		if(operators[i] == '^'){
			numbers[i+1] = power(numbers[i], numbers[i+1]);

			numbers[i] = 0;
			
		}else if(operators[i] == '*'){
			numbers[i+1] = multiply(numbers[i], numbers[i+1]);
			if(operators[i-1] == '-') -1 * numbers[i+1];

			numbers[i] = 0;	
			
		} else if(operators[i] == '/'){
			numbers[i+1] = divide(numbers[i], numbers[i+1]);
			if(operators[i-1] == '-') -1 * numbers[i+1];

			numbers[i] = 0;
	
		}
	}		
	for(int i = 0; i <= nOp; ++i){
		result = result + numbers[i];	
		
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
	char funct[100];
	double sign;
	int nNum, nOp;

	parseString(input, numbers, operators, funct, &sign, &nNum, &nOp);
	func(funct, numbers, nNum);

	for (int i = 0; i < nNum; ++i)
		printf("%.2f ", numbers[i]);
	printf("\n");
	for (int i = 0; i < nOp; ++i)
		printf("%c ", operators[i]);
	printf("\n");
		
	printf("%.2f\n", operationOrder(operators, numbers, &sign, funct, nOp));
	double x = 0;
	return 0;
}
