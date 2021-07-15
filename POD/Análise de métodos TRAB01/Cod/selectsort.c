#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selection_sort_crescent(int array[], int n){
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

void selection_sort_decrescent(int array[], int n){
    int i, j, min_id;
    for (i = 0; i < n-1; i++){
        min_id = i;
        for (j = i+1; j < n; j++){
          if (array[j] > array[min_id])
            min_id = j;
        }    
        swap(&array[min_id], &array[i]);
    }
}
 
void print(int array[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("arrayPOS[%d]: %d\n", i, array[i]);        
}

void random_array(int array[]){
    for(int i = 0; i < 100000; i++){
        array[i] = rand()%100000;
    }   
    for(int i = 0; i < 100000; i++){
        printf("arrayPOS[%d]: %d\n", i, array[i]);
    }   
}

 
// Driver program to test above functions
int main(){
    clock_t t;
    int array[100000];
    double t1, t2, t3;
    int n = sizeof(array)/4;
    
    printf("\nCriação e listagem do vetor aleatório: \n");
    t = clock(); 
    random_array(array);
    t = clock() - t;
    t1 = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("\n");
    
    t = clock(); 
    selection_sort_crescent(array, n);
    t = clock() - t;
    t2 = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("Vetor ordenado selection sort(CRESCENTE): \n");
    print(array, n);
    printf("\n");

    t = clock(); 
    selection_sort_decrescent(array, n);
    t = clock() - t;
    t3 = ((double)t)/((CLOCKS_PER_SEC/1000));
    printf("Vetor ordenado selection sort(DECRESCENTE): \n");
    print(array, n);

    printf("\n\nTempo de criação e listagem aleatória: %lf\nTempo de execução crescente: %lf\nTempo de execução descrescente: %lf\n\n", t1, t2, t3); //millisec


    return 0;
}
//O(n²)

