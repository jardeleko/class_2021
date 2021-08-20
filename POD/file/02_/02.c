#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selection_sort(int array[], int n){
    int i, j, min_id;
    for (i = 0; i < n-1; i++){
        min_id = i;
        for (j = i+1; j < n; j++){
          if (array[j] < array[min_id])
            min_id = j;
        }    
        swap(&array[min_id], &array[i]);
    }
}

int main() {
    // gravacao
    int vet[20];
    int n = sizeof(vet)/4;


    FILE *arq = fopen("numeros.txt", "wt"); // gravacao e leitura em novo arquivo
    if(arq == NULL){
        printf("Não foi possível criar o arquivo!");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        vet[i] = rand()%125;
        fprintf(arq, "%d, \n", vet[i]);
    }

    printf("\n\n");
    selection_sort(vet, n);


    FILE *fp = fopen("numeros_ord.txt", "w+t"); 
    if(fp == NULL) exit(1);
    for(int i = 0; i < n; i++) fprintf(fp, "%d\n", vet[i]);
    fclose(fp);
    return 0;
}