#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

typedef struct aluno{
    char nome[MAX];
    float n1, n2;   
} Aluno;


size_t create_student( FILE * pf, char * nome, float n1, float n2){
    Aluno tmp;
    strcpy(tmp.nome, nome);
    tmp.n1 = n1;
    tmp.n2 = n2;

    return fwrite( &tmp, sizeof(Aluno), 1, pf);
}


void list_students( FILE * pf){
    Aluno tmp;
    float mid;
    while(fread( &tmp, sizeof(Aluno), 1, pf)){
      mid = (tmp.n1+tmp.n2)/2;
        if( mid <= 7){   
          printf( "Nome: %s\t\t|\n", tmp.nome );
          printf( "n1: %.2f\t\t|\n", tmp.n1 );
          printf( "n2: %.2f\t\t|\n", tmp.n2 );
          printf( "------------------------\n" );
          printf("Media aritmética: %.2f\n", mid);
          printf( "------------------------\n\n" );
          break;
        }
        else if(mid > 7){
          printf( "Nome: %s\t\t|\n", tmp.nome );
          printf( "n1: %.2f\t\t|\n", tmp.n1 );
          printf( "n2: %.2f\t\t|\n", tmp.n2 );
          printf( "------------------------\n" );
          printf("Media aritmética #aprovados: %.2f\n", mid);
          printf( "------------------------\n\n" );
          break;
        }
    }
}


int main( int argc, char ** argv ){
    FILE *arq = NULL;
    /* Abre arquivo para gravacao em modo binario... */
    arq = fopen( "list.bin", "wb");
    int n;
    double aux, aux2;
    char name[51];
    if(!arq) exit(1);

    printf("insira a quantidade de alunos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
      getchar();
      printf("nome: \n");
      fgets(name, 51, stdin);
      printf("primeira nota: \n");
      scanf("%lf", &aux);
      printf("segunda nota: \n");
      scanf("%lf", &aux2);
      create_student(arq, name, aux, aux2);
      fflush(arq);
    }
    fclose(arq);
    
    arq = fopen( "list.bin", "rb");

    if(!arq) printf("err\n"), exit(1);
    for(int i = 0; i < n; i++) list_students(arq);
    fclose(arq);

    getchar();
    return 0;
}