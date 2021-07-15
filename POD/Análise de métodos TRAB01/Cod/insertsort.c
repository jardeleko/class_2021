
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 

void insertion_sort_asc(int array[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void insertion_sort_desc(int array[], int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void random_array(int array[]){
    for(int i = 0; i < 100000; i++){
        array[i] = rand()%100000;
    }   
    for(int i = 0; i < 100000; i++){
        printf("arrayPOS[%d]: %d\n", i, array[i]);
    }   
}


void print(int array[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("arrayPOS[%d]: %d\n", i, array[i]);
    printf("\n");
}
 
int main(){
    int array[100000];
    clock_t t;
    double t1, t2, t3;

    t = clock(); 
    random_array(array);
    t = clock() - t;
    t1 = ((double)t)/((CLOCKS_PER_SEC/1000));

    int n = sizeof(array) / 4;
    t = clock(); 
    insertion_sort_asc(array, n);
    t = clock() - t;
    t2 = ((double)t)/((CLOCKS_PER_SEC/1000));

    print(array, n);

    t = clock(); 
    insertion_sort_desc(array, n);
    t = clock() - t;
    t3 = ((double)t)/((CLOCKS_PER_SEC/1000));

    print(array, n);

    printf("\n\nTempo de criação e listagem aleatória: %lf\nTempo de execução crescente: %lf\nTempo de execução descrescente: %lf\n\n", t1, t2, t3); //millisec
    return 0;
}