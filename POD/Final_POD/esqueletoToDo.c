#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 100 //definindo um total de até 100 tarefas
#define EXIT 10  // valor fixo para a opção que finaliza a aplicação

//Struct que representa a data.
typedef struct {
	int day;
	int month,
} Date;

typedef struct {
     item_list *head;
     item_list *tail;
} List;

// Estrutura que contém os campos dos registros das tarefas
struct REC {
       int prioridade;
       char nome[50];
       Date entrega; 
	  struct REC *next; // implemente como lista, como árvore BST, AVL...
	  struct REC *prev;
};

// Tipo criado para instanciar variaveis do tipo acima
typedef struct REC Task;

viod insert_list(List *lista, REC *anterior, REC *elemento){
     if(anterior == NULL){
          lista->head->next = elemento;
          elemento->prev = item_ant;
          elemento->next = item_prox;
     }
}



// Apresenta o menu da aplicação e retorna a opção selecionada
int menu()
{
    int op=0;
    while (op!=EXIT)  {
        printf("%d Finaliza",EXIT);
        printf("\n: ");
        scanf("%d",&op);
       
    }
    return op;
}

// Permite o cadastro de uma tarefa
void insTask()
{
     return;
}

// Permite excluir uma tarefa
void delTask ()
{
     return;
}

// Lista o conteudo da lista de tarefas (todos os campos)
void listTasks ()
{
     return;
}

// Permite consultar uma tarefa da lista pelo nome
void querytask ()
{
     return;
}

// Permite a atualização dos dados de uma tarefa
void upTask ()
{
     return;
}

// Programa principal
int main()
{
    int op=0;
    Task t;

    while (op!=EXIT)
    {
          op=menu();
          switch(op)
          {
              case 1 : insTask();
              case 2 : delTask();
              case 3 : upTask();
              case 4 : queryTask();
              case 5 : listTasks();
          }
    }
    return 0;
}
