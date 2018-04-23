
#include<stdio.h>
#include<stdlib.h>
#include "listaEncadeada.h"
#include "listaDuplamenteEncadeada.h"
#include "listaCircular.h"


int main(){

int num_insert=0;
//start

NodeE *listE = startE();
NodeDE *listDE = startDE();
NodeC *head = NULL;

//Lista Simplesmente Encadeada
isEmptyE(listE);
memory_allocateE(listE);
printf("Type how many number to insert");
scanf("%d",&num_insert);
do{
  insertE(listE);
  num_insert--;
}while(num_insert>=0);

searchBigE(listE);
searchSmallE(listE);
removeFirstE(listE);
removeLastE(listE);
printE(listE);

//Lista Duplamente Encadeada

isEmptyDE(listDE);
do{
  insertDE(listDE);
  num_insert--;
}while(num_insert>=0);

searchBigDE(listDE);
searchSmallDE(listDE);
removeStartDE(listDE);
removeEndDE(listDE);
insertEndDE(listDE);
printDE(listDE);

//Lista Circular

memory_allocateC(head);
do{
  insertC(head);
  num_insert--;
}while(num_insert>=0);
searchBigC(head);
searchSmallC(head);
removeEndC(head);
removeStartC(head);
insertEndC(head);
printC(head);

return 0;
}
