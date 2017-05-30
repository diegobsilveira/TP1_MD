// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DE COMPUTAÇÃO - DCC
// -- DCC111 - MATEMATICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula: 201705169
// -- Código: analise2.c

#include <stdlib.h>
#include <stdio.h>

int main(int main, char* argv[]) {
	int i, j,	//Variáveis para controlar os loops.
	    r, n;	//Variáveis definidas pelo input do usuário, 
			//de  controle, para imprimir a permutação sem
			//repetição para o usuário.

	printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 20) respectivamente: \n");
	scanf("%d%d", &r, &n);
	
	if((r < 2 || r > 10) || (n < 1 || n > 20)) {
		printf("Algum dos valores digitados está fora do seu respectivo intervalo válido! Digite novamente\n");

		do {
			printf("Digite o valor de r(2 <= r <= 10) e n(1 <= n <= 20) respectivamente: \n");
			scanf("%d%d", &r, &n);
		} while((r < 2 || r > 10) || (n < 1 || n > 20));	
	}
	
	printf("\nPermutação sem repetição: \n");
		
	int valorAtual = 1;
	for(i = 0; i <= r; i++) {
		while(valorAtual <= n) {
			printf("%d %d\n", i+1, valorAtual);
			valorAtual++;	
		}
		valorAtual = 1;	
	}

	printf("\n");
	return 0;
}
