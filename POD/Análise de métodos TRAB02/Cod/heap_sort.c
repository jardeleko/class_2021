#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void swap(int *i, int *j){
	int tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
}

void createheap( int arr[], int n){
	int f, s;
	for(int i=1; i<n; i++){
		s = i;
		f = (i-1)/2;
		while(arr[f] < arr[s]){
			swap( &arr[f], &arr[s]);
			s = f;
			if ( s == 0) 
				break;
			
			f = (s-1)/2;
		}
	}
}

void heapsort( int arr[], int n){
	for(int i = n-1; i >= 1; i--){
		swap(&arr[0], &arr[i]);
		createheap(arr, i);
	}
}

int main(){
	int arr[100000];
	clock_t t;
	double t1, t2;
	int arr_size = sizeof(arr) / sizeof(arr[0]);

   	t = clock(); 
	for (int i=0; i< arr_size; i++){
		arr[i] = rand()%arr_size;
	}
    t = clock()-t; 
   	t1 = ((double)t)/((CLOCKS_PER_SEC/1000));
	createheap(arr, arr_size);

   	t = clock(); 
	heapsort(arr,arr_size-1);
   	t = clock()-t; 
   	t2 = ((double)t)/((CLOCKS_PER_SEC/1000));
	
	for (int i=0; i< arr_size; i++){
		printf(" %d ", arr[i]);
	}
	
	printf("\n");
    printf("\n\nTempo de execução valores aleatórios: %lf\nTempo de execução valores ordenados: %lf\n\n", t1, t2); 

	return 0;
}

