#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX 100

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
		exit(1);
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
		if(isdigit(input[i]) || input[i] == '.' && isdigit(input[i+1] )) {
			numbers[*nNum] = strtod(input + i, NULL);
			

			while (isdigit(input[i]) || input[i] == '.') ++i;
			--i;

			(*nNum)++;

		}else if(isOperator(input[i]) && i != 0) {
			operators[*nOp] = input[i];

			(*nOp)++;
	        }else if(input[i] == 's' && input[i+1] == 'i' && input[i+2] == 'n'){
			func[*nOp] = 's';
			i = i+2;

		}else if(input[i] == 'c' && input[i+1] == 'o' && input[i+2] == 's'){
			func[*nOp] = 'c';
			i = i+2;
		}else if(input[i] == 't' && input[i+1] == 'a' && input[i+2] == 'n'){
			func[*nOp] = 't';
			i = i+2;
		}else if(input[i] == 'l' && input[i+1] == 'n'){
			func[*nOp] = 'n';
			i = i+1;
		}else if(input[i] == 'l' && input[i+1] == 'o' && input[i+2] == 'g'){
			func[*nOp] = 'l';
			i = i+2;
		}else if(input[i] == 's' && input[i+1] == 'q' && input[i+2] == 'r' && input[i+3] == 't'){
			func[*nOp] = 'r';
			i = i+3;
		}
	}
}

void func(char *func, double *numbers, int nNum){
	for(int i = 0; i <= nNum; ++i){
		if(func[i] == 's'){
			numbers[i] = sin(numbers[i] * (PI / 180));
		}else if(func[i] == 'c'){
			numbers[i] = cos(numbers[i] * (PI / 180));
		}else if(func[i] == 't'){
			if(fmod(numbers[i], 90) == 0.0 && fmod(numbers[i], 180) != 0.0){
				printf("error\n");
				exit(1);
			}else{ 
				numbers[i] = tan(numbers[i] * (PI / 180));
			}
		}else if(func[i] == 'n'){
			if(numbers[i] <= 0){
				printf("error\n");
				exit(1);
			}else{
				numbers[i] = log(numbers[i]);
			}
		}else if(func[i] == 'l'){
			if(numbers[i] <= 0){
				printf("error\n");
				exit(1);
			}else{
				numbers[i] = log10(numbers[i]);
			}
		}else if(func[i] == 'r'){
			if(numbers[i] < 0){
				printf("error\n");
				exit(1);
			}else{
				numbers[i] = sqrt(numbers[i]);
			}
		}
	}
}

double operationOrder(char *operators, double *numbers, double *sign, char *input, int nOp){
	double result = 0;
	if(isOperator(input[0]))  
		numbers[0] = *sign * numbers[0];
	
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
	char input[MAX];
	double numbers[MAX];
	char operators[MAX];
	char funct[MAX];
	double sign;
	int nNum, nOp;
	double result;

	getString(input, sizeof(input));
	parseString(input, numbers, operators, funct, &sign, &nNum, &nOp);
	func(funct, numbers, nNum);
	result = operationOrder(operators, numbers, &sign, input, nOp);

	printf("%s = %.*f\n",input, 4, result);
	

	return 0;
}
