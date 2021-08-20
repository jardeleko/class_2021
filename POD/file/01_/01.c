
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char c;
    FILE *fp;
    int bl = 0;
    int ws = 0;
    int count = 0;
    if ((fp=fopen("file.txt", "r"))==NULL) {
        printf("ops, ERROR");
        exit(1);
    }

    while(!feof(fp)){          
        c=getc(fp), ++count;
        if(c==' ') ++ws;
        if(c=='\n') ++bl;     
    }

    

    printf("Geral: %d\n", count);
    printf("Espaços em branco: %d\n", ws);
    printf("Quebra de linha: %d\n", bl);
    return (0);
    getchar();
    getchar();
}