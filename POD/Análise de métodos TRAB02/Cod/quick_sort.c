#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
 
void quick_sort(int arr[],int f, int l){
   int i, j, pivot, tmp;

   if(f < l){
      pivot=f; //pivot recebe first
      i=f; //i recebe inicio
      j=l; //j recebe fim last

      while(i < j){
         while(arr[i]<=arr[pivot]&&i<l)
            i++;
         while(arr[j]>arr[pivot])
            j--;
         if(i<j){
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
         }
      }

      tmp=arr[pivot];
      arr[pivot]=arr[j];
      arr[j]=tmp;
      quick_sort(arr,f,j-1);
      quick_sort(arr,j+1,l);

   }
}

int main(){
   int i, arr[100000];
   clock_t t;
   double t1, t2;
   int arr_size = sizeof(arr) / sizeof(arr[0]);

   t = clock(); 
   for (int i = 0; i < arr_size; i++) {
      arr[i] = rand()%arr_size;
   }
   t = clock() -1;
   t1 = ((double)t)/((CLOCKS_PER_SEC/1000));

   printf("Aleatório: \n");
   for(i=0;i < arr_size; i++) printf(" %d ",arr[i]);
   printf("\n");

   t = clock();
   quick_sort(arr, 0, arr_size-1);
   t = clock()-t;
   t2 = ((double)t)/((CLOCKS_PER_SEC/1000));   
   
   printf("\n Elementos ordenados: \n");
   for(i=0;i < arr_size; i++) printf(" %d ",arr[i]);
   printf("\n");
   printf("\n\nTempo de execução valores aleatórios: %lf\nTempo de execução valores ordenados: %lf\n\n", t1, t2); 

   return 0;
}