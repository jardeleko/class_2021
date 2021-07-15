#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* vetores temporarios */
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
 
    i = 0; // indice inicial do vetor da esquerda da arvore
    j = 0; // indice inicial do vetor da direita
    k = l; //indece do subarray do merge

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void merge_sort(int arr[], int l, int r){
    if (l < r) {
        //Divide arvore
        int m = l + (r - l) / 2;
 
        //divide  e ordena
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
 

void print_array(int A[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 

int main(){
    int arr[100000];
    clock_t t;
    double t1, t2;
    
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    t = clock(); 
    for(int i = 0; i < arr_size; i++){
        arr[i] = rand()%arr_size;
    }
    t = clock() - t;
    t1 = ((double)t)/((CLOCKS_PER_SEC/1000));

    printf("\nCom valores aleatórios: \n");
    print_array(arr, arr_size);

    t = clock();
    merge_sort(arr, 0, arr_size - 1);
    t = clock() - t;
    t2 = ((double)t)/((CLOCKS_PER_SEC/1000));

    printf("\nCom valores ordenados: \n");
    print_array(arr, arr_size);
    printf("\n\nTempo de execução valores aleatórios: %lf\nTempo de execução valores ordenados: %lf\n\n", t1, t2); 

    return 0;
}