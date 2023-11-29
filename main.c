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

double sinus(double a){
	return sin(a);
}

double cosinus(double a){
	return cos(a);
}

double tangens(double a){
	return tan(a);
}

 /*void getString(char *string, int size){
	printf("Vnesi racun: ");
	fgets(string, size, stdin);

	int lenght = strlen(string);

	if (lenght > 0 && string[lenght-1] == '\n') string[lenght-1] = '\0';
}*/

int main(void){
	/*char string[100];
	getString(string, sizeof(string));*/

	char input[100];
	double num;

	printf("Vnesi izraz: ");
	fgets(input, sizeof(input), stdin);

	printf("%s\n", input);



	return 0;
}
