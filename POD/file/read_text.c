#include <stdio.h>
#include <string.h>
 int main(void){
     int numeroCaracteres = 0;
     char caractere = getchar();
     while (caractere != '\n')
     {
         numeroCaracteres = numeroCaracteres + 1;
        caractere = getchar();
    }
    printf("%d\n", numeroCaracteres);
    return 0;
}