// -- UNIVERSIDADE FEDERAL DE MINAS GERAIS - UFMG
// -- DEPARTAMENTO DE CIÊNCIA DE COMPUTAÇÃO - DCC
// -- DCC111 - MATEMATICA DISCRETA - 2017/1
// -- Nome: Diego Barros da Silveira
// -- Matrícula: 201705169
// -- Código: analise2.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>    //Para utilizar tipos booleanos - true | false

//r é o tamanho da sequência, como definido no problema e na int main()
int* inicializaSequencia(int r) {
	int i; 						//controle do loop para inicializar a sequência
	int* sequencia = (int *)(malloc(r * sizeof(int)));

	if(sequencia == 0 || sequencia == NULL) {		//Caso não foi possível fazer a alocação dinâmica de um vetor (que representa a sequência deste problema).								//com 'r' elementos.
		printf("Erro! Não possível alocar a sequência! Rode o programa novamente");
		exit(1);
	}

	for(i = 0; i < r; i++)
		*(sequencia + i) = 1;
				
	return sequencia;
}

//Imprime a sequência atual
//*Nota, como foi usado um vetor, as posições tem que ser impressas "em reverso" para aparecerem do jeito que são
//no vetor e em ordem crescente.
void imprimeSequencia(int r, int* sequencia) {
	int i;
	for(i = r - 1; i > 0; i--)
		printf("%d ", *(sequencia + i));

    printf("%d\n",*(sequencia + i));
}

//Checa se ainda dá para permutar e já define os valores de uma única permutação de uma vez na 'sequencia' 
bool proxPermutRepet(int r, int n, int* sequencia) {
	int i,                                  //Variável de controle para acessar as posições do vetor 'sequencia'.
		posix = 1;                          //Variável de controle que será
		                                    //usada para já setar e rodar ""recursivamente"" o algoritmo - no sentido de
                                            //que ele roda para as posições i < posix, que será modificado também dentro
                                            //do for
                                            
	for(i = 0; i < posix; i++) {      //Loop que roda por todas as posições do vetor
	                                        //de acordo com a incrementação de posix
	                                        
		if(++sequencia[i] > n) {            //Equivalente à um while - enquanto o valor do vetor sequencia for menor do que n
			sequencia[i] = 1;               //Mas se for maior reseta a posição 'i' para 1,
			                                //para recomeçar a contagem.
			if(i < (r - 1))                 //e vai fazendo isso para todas as posições menos significativas até a posição                                 //atual
			                                //até todas as posições do vetor
				posix++;
			else
				return false;               //terminou o 'loop'
		}
		
	}
	
	return true;                            //conseguiu fazer as devidas modificações no vetor.
}

//Checa se um mesmo valor está no vetor mais de uma vez
bool valorJaExiste(int r, int* sequencia) {
	int i, j;
	for(i = 0; i < r; i++) {
		for(j = 0; j < r; j++) {
			if((sequencia[i] == sequencia[j]) && (i != j))
			    return true;
		}
	}

	return false;
}

//Faz a permutação sem repetição repetição da sequência e imprime na tela;
void imprimePermutaSemRepet(int r, int n) {
	int* sequencia = inicializaSequencia(r);		//Inicializa uma sequência de tamanho r.

	do{
	    if(!(valorJaExiste(r, sequencia))) {            //Imprime o valor se não existirem algarismos
	                                                    //repetidos na sequência formada pela permutação com repetição 
	                                                    // - isso forma a sem repetição
	                                                    
	                                                    
            imprimeSequencia(r, sequencia);				//Imprime o valor da sequência atual
            fflush(stdout);								//Limpa o buffer de saída, para agilizar a saída dos dados na tela.    
	    }
    }while(proxPermutRepet(r, n, sequencia));

    free(sequencia);
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
    	imprimePermutaSemRepet(r, n);

	return 0;
}
