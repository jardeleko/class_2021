#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


int bubblesort_crescent(int array[]){
	int flag = 1, aux, i;
	while (flag == 1){
		flag = 0;
		for(i = 0; i < 100000; i++){	
			if(array[i] > array[i+1]) 
				flag = 1, aux = array[i], array[i] = array[i+1], array[i+1] = aux;
	      	
	    }
	}
}

int bubblesort_decrescent(int array[]){
	int aux, flag = 1, i;
	while (flag == 1){
		flag = 0;
		for(i = 0; i <= 100000; i++){
			if(array[i] < array[i+1]) 
				flag = 1, aux = array[i + 1], array[i + 1] = array[i], array[i] = aux;
	    }
	}
}

void bubble_random(int array[]){
	for(int i = 0; i < 100000; i++){
        array[i] = rand()%100000;
    }	
    for(int i = 0; i < 100000; i++){
		printf("arrayPOS[%d]: %d\n", i, array[i]);
    }	
}


int main (void){
/*	int n;
	printf("entre com o tamanho do vetor: ");
	scanf("%d", &n);*/
	int array[100000];
	int i;
	clock_t t;
	double t1, t2, t3;

	t = clock(); 
	bubble_random(array);
    t = clock() - t;
    t1 = ((double)t)/((CLOCKS_PER_SEC/1000));

	for (i = 0; i < 100000; i++)	printf("arrayPOS[%d]: %d\n", i, array[i]);
	printf("\n");
	
	t = clock(); 
	bubblesort_crescent(array);
	t = clock() - t;
    t2 = ((double)t)/((CLOCKS_PER_SEC/1000));
	for (i = 0; i < 100000; i++)	printf("arrayPOS[%d]: %d\n", i, array[i]);

	t = clock(); 
	bubblesort_decrescent(array);
	t = clock() - t;
    t3 = ((double)t)/((CLOCKS_PER_SEC/1000));
	
	for (i = 0; i < 100000; i++)	printf("arrayPOS[%d]: %d\n", i, array[i]);
	printf("\n");
	


    printf("\n\nTempo de criação e listagem aleatória: %lf\nTempo de execução crescente: %lf\nTempo de execução descrescente: %lf\n\n", t1, t2, t3); //millisec

	return 0;
}

/*


a - Gerar 3 vetores: um em ordem crescente, outro em ordem decrescente e outro em ordem aleatória 
(totalmente desordenado).
b - Para cada vetor gerado no item a:
b1 - Captar a contagem do tempo atual (clock) antes de chamar a ordenação;
b2 - Chamar a função de ordenação para o vetor;
b3 - Captar a contagem de tempo após chamar a ordenação;
b4 - Calcular a diferença de tempo e exibir em segundos (ou milisegundos)
c - Anotar esta contagem de tempo e colocar em uma planilha ou tabela.

Ou seja, devemos testar cada método com 3 tamanhos de entrada e, para cada tamanho, 
com os 3 casos de ordem inicial;

Após obter os tempos e sintetizar os resultados em uma tabela, 
fazer um gráfico para cada método mostrando como o tempo de execução se altera em função da quantidade de dados.

Analise os resultados e escreva suas conclusões a respeito do comportamento de dada método. 
Descreva também o hardware utilizado (processador e memória).

Envie compactados o(s) programa(s) e um arquivo DOC (ou ODT) com as análises.*/
