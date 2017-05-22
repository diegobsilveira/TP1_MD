// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DE COMPUTAÇÃO - DCC
// -- DCC111 - MATEMATICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula: 201705169

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int geraValorInicial(int n) { 
	int val = 0;
	 while(n >= 1) { 
		val += pow(10, n - 1);
		n--;
	}
	return val;
}

int digitoMaisSignificativo(int n) {
	while(n > 9)
		n /= 10; 
	return n;
}

int digitoMenosSignificativo(int n) {
	return (n % 10);
}

int arredondaProximoMultiplo10(int n) {
	if(n % 10)
 	   n = n + (10 - n % 10);	
	return n;
}

int main(int main, char* argv[]) {
	int i, j,	//Variáveis para controlar os loops.
	    r, n;	//Variáveis definidas pelo input do usuário, 
			//de  controle, para imprimir a permutação com
			//repetição para o usuário.

	printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 20) respectivamente: \n");
	scanf("%d%d", &r, &n);
	
	if((r < 2 || r > 10) || (n < 1 || n > 20)) {
		printf("Algum dos valores digitados está fora do seu respectivo intervalo válido! Digite novamente\n");

		do {
			printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 20) respectivamente: \n");
			scanf("%d%d", &r, &n);
		} while((r < 2 || r > 10) || (n < 1 || n > 20));	
	}
	
	printf("\nPermutação com repetição:\n");

	int valorInicial  = geraValorInicial(r);
	int valorLoop = valorInicial;

	for(i = 1; i <= pow(n, r); i++) {
		printf("%d \n", valorLoop);
		if(digitoMenosSignificativo(valorLoop)  == n)
			valorLoop =  arredondaProximoMultiplo10(valorLoop) + 1;
		else
			valorLoop++;
	}	
 
	return 0;
}
