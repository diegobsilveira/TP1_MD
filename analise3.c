// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DE COMPUTAÇÃO - DCC
// -- DCC111 - MATEMATICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula: 201705169
// -- Código: analise3.c

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

void combinaRepet(int r, int n) {
	int i, j, k;
	int* combinacao = inicializaSequencia(r);

	//Como é um vetor, o elemento mais à direita é o 'algarismo menos significativo' na hora de imprimir
	for(i = r - 1; i >= 0; i--) {						//Vai do algarismo 'menos significativo' até o 'mais significativo'
	    for(j = r - 1; j >= i; j--) {                   //Vai do algarismo 'menos significativo' até a posição atual ('i') e
	        while(combinacao[r - 1] <= n) { 
	            imprimeSequencia(r, combinacao);
                fflush(stdout);
                
                combinacao[r - 1]++;
            }
            if(i > 0) {
                combinacao[i - 1]++; 
                for(k = i; k < r; k++)                            //Para todas as posições anterioes
                    combinacao[k] = combinacao[i - 1];                //Iguala elas à atual, até a última (mais a direita) ao valor da próxima incrementada.
            } 
	    }
    }
}

int main(int argc, char* argv[]) {
	int r, n;	//Variáveis definidas pelo input do usuário, 
    			//de  controle, para imprimir a permutação com
    			//repetição para o usuário.

	printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 5) respectivamente: \n");
	scanf("%d%d", &r, &n);
	
	if((r < 2 || r > 10) || (n < 1 || n > 5)) {
		printf("Algum dos valores digitados está fora do seu respectivo intervalo válido! Digite novamente\n");

		do {
			printf("Digite o valor de r (2 <= r <= 10) e n (1 <= n <= 5) respectivamente: \n");
			scanf("%d%d", &r, &n);
		} while((r < 2 || r > 10) || (n < 1 || n > 5));	
	}
	
	//int* sequencia = inicializaSequencia(r);	
	printf("\nCombinação com repetição: \n");
    combinaRepet(r, n);

	return 0;
}
