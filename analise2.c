// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DE COMPUTAÇÃO - DCC
// -- DCC111 - MATEMATICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula: 201705169
// -- Código: analise2.c

#include <stdlib.h>
#include <stdio.h>

//r é o tamanho da sequência, como definido no problema e na int main()
int* inicializaSequencia(int r) {
	int i; 						//controle do loop para inicializar a sequência
	int* sequencia = (int *)(malloc(r * sizeof(int)));

	if(sequencia == 0 || sequencia == NULL) {		//Caso não foi possível fazer a alocação dinâmica de um vetor (que representa a sequência deste problema).								//com 'r' elementos.
		printf("Erro! Não possível alocar a sequência! Rode o programa novamente");
		exit(1);
	}

	for(i = 0; i < r; i++)
		*(sequencia + i) = i + 1;	//Pois nesse caso os elementos
						//não podem ser repetidos.
	return sequencia;
}

//Imprime a sequência atual
void imprimeSequencia(int r, int* sequencia) {
	int i;
	for(i = 0; i < r; i++)
		printf("%d ", *(sequencia + i));
        
    	printf("\n");
}

//Troca o valor da posição de 'pos' com 'troc' e de 'troc' com 'pos'
void troca(int pos, int troc, int tam, int* sequencia) {
	if((pos <= tam - 1 && pos >= 0 ) && (troc <= tam- 1 && troc >= 0)) {
		if(pos == troc)
			return;
		int aux = *(sequencia + pos);		//Variável auxiliar pra guardar o valor inicial da posição 'pos' - que será colocado na posição 'troc';
		*(sequencia + pos) = *(sequencia + troc);
		*(sequencia + troc) = aux;
	} else {
		printf("Não foi possível trocar as posições %d e %d\n", pos, troc);
		return;
	}
}

void permutSemRepet(int r, int n) {
	int i, j;

	int* sequencia = inicializaSequencia(r);

	for(i = r - 1; i > 0; i--) {
		imprimeSequencia(r, sequencia);
		troca(0, r - i, r, sequencia);
	}
}

int main(int argc, char* argv[]) {
	int r, n;	//Variáveis definidas pelo input do usuário, 
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

	if(r > n) {
		printf("Erro, uma permutação sem repetição não pode ter uma quantidade de elementos maior do que o maior elemento possível!");
		printf("\nRode o programa novamente!\n");
		exit(1);	
	}

	printf("\nPermutação sem repetição: \n");
    	permutSemRepet(r, n);

	return 0;
}
