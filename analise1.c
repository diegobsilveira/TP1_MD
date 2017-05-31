// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DA COMPUTAÇÃO - DCC
// -- DCC111 - MATEMÁTICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula:  2017015169
// -- Código: analise1.c

#include <stdlib.h>
#include <stdio.h>

//r é o tamanho da sequência, como definido no problema e na int main()
int* inicializaSequencia(int r) {
	int i; 						//controle do loop para inicializar a sequência
	int* sequencia = (int *)(malloc(r * sizeof(int)));

	if(sequencia == 0 || sequencia == NULL) {		//Caso não foi possível fazer a alocação dinâmica de um vetor (que representa a sequência deste r								// oblema).
							        //com 'r' elementos.
		printf("Erro! Não possível alocar a sequência! Rode o programa novamente");
		exit(1);
	}

	for(i = 0; i < r; i++)
		*(sequencia + i) = 1;	//O valor em cada uma das posições da sequência, incialmente, é 1.

	return sequencia;
}

//Imprime a sequência atual
void imprimeSequencia(int r, int* sequencia) {
	int i;
	for(i = 0; i < r; i++)
		printf("%d ", *(sequencia + i));
	printf("\n");
}

//Faz a permutação com repetição da sequência e imprime na tela;
void permutaRepet(int r, int n) {
	int i, j, k;
	int* sequencia = inicializaSequencia(r);		//Inicializa uma sequência de tamanho r.

	/*
	//Como é um vetor, o elemento mais à direita é o 'algarismo menos significativo' na hora de imprimir	
	for(i = r - 1; i >= 0; j++) {
		while(sequencia[r - 1] <= n) {	//Enquanto o valor da posição atual for menor ou igual a 'n'
			imprimeSequencia(r, sequencia);
			fflush(stdout);			//Limpa o buffer de saída dos dados, para agilizar a impressão dos mesmos.
				
			sequencia[r - 1]++;		//Incrementa o valor da posição corrente até ela ser igual ao número máximo ('n').
		}

		if(sequencia[i] == n) {
			sequencia[i - 1]++;
			sequencia[i] = 1;
		} else {
			sequencia[i]++;
		}
	} */
	for(i = r -1; i >= 0; i--) {						//Vai do algarismo 'menos significativo' até o 'mais significativo'
		for(j = r - 1; j >= i; j--) {
			while(sequencia[r - 1] <= n) {	//Enquanto o valor da posição atual for menor ou igual a 'n'
				imprimeSequencia(r, sequencia);
				fflush(stdout);			//Limpa o buffer de saída dos dados, para agilizar a impressão dos mesmos.
				
				sequencia[r - 1]++;		//Incrementa o valor da posição corrente até ela ser igual ao número máximo ('n').
			}

			for(k = r - 1; k >= i; k--) {
				if(sequencia[k] == n) {
					sequencia[k] = 1; 			//quando termina de contar até 'n' uma posição, volta o valor dela para 1
					sequencia[k - 1]++;		//e aumenta um no valor da anterior, pra fazer essa 'contagem' com essa outra posição
				}
			}
		}
	}
}

int main(int main, char* argv[]) {
	int r, n;   	//Variáveis definidas pelo input do usuário,
	    		//de  controle, para imprimir a permutação com
			//repetição para o usuário.

	printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 20) respectivamente: \n");
	scanf("%d%d", &r, &n);
	
	if((r < 2 || r > 10) || (n < 1 || n > 20)) {            //Se algum dos valores digitados está fora de seu intervalo válido
		printf("Algum dos valores digitados está fora do seu respectivo intervalo válido! Digite novamente\n");

		do {
			printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 20) respectivamente: \n");
			scanf("%d%d", &r, &n);                                                                  //O usuário digita novamente ...
		} while((r < 2 || r > 10) || (n < 1 || n > 20));	                                        //até o valor digitado ser válido
	}
	
	printf("\nPermutação com repetição:\n");

	permutaRepet(r, n);				//Imprime a permutação da sequência, de acordo com 'r' e 'n' digitados pelo usuário
	
	return 0;
}
