#include <iostream>
using namespace std;

int main ()
{
	char operador;
	double nmr1 , nmr2;
	
	printf("Digite a operacao que deseja realizar: \n Adicao digite: + \n Subtracao digite: -\n Multiplicacao digite: *\n Divisao digite: / \n");
	scanf("%c", &operador);
	
	printf("Digite dois numeros para realizar essa operacao:\n");
	scanf("%lf %lf", &nmr1, &nmr2);
	
	switch(operador) {
		case'+':
			printf("O resultado da soma eh: %.2lf", nmr1 + nmr2);
			break;
		case '-':
			printf("O resultado da subtração eh: %.2lf", nmr1 - nmr2);
			break;
		case '*':
			printf("O resultado da multiplicacao eh: %.2lf", nmr1 * nmr2 );
			break;
		case '/':
			if (nmr2 != 0) {
			printf("O resultado da divisao eh: %.2lf", nmr1 / nmr2);
		   }else {
		   	printf("Erro! Divisao por zero.");
		   }
			break;
		default:
			printf("O operador digitado eh invalido!");
			
	}
	
	return 0;
	
	
}
