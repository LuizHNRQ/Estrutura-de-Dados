
// Luiz Henrique Barros Teixeira

//SO33A-ES31

//Create a File of a client and print the info
#include<stdio.h>
#include<stdlib.h>

void read();
void print();

typedef struct Client{

    char name[50];
    char street[50];
    int  number;
    char city[30];
    char state[30];
    char cep[9];/* postal code */

}ClientFile;

ClientFile *ptr;

int main(){

 ptr = (ClientFile*)malloc(sizeof(ClientFile));

    read();
    print();

return 0;
}

void read(){

    printf("\t CLIENT FILE\n\n");
    printf("Type the name\n- ");
    scanf("%s",&ptr[0].name);
    printf("Type the street\n- ");
    scanf("%s",&ptr[0].street);
    printf("Type the number\n- ");
    scanf("%d",&ptr[0].number);
    printf("Type the city\n-");
    scanf("%s",&ptr[0].city);
    printf("Type the state\n-");
    scanf("%s",&ptr[0].state);
    printf("Type the CEP\n-");
    scanf("%s",&ptr[0].cep);


}

void print(){

    printf("NAME\n-%s\n",ptr[0].name);
    printf("STREET\n-%s\n",ptr[0].street);
    printf("NUMBER\n-%d\n",ptr[0].number);
    printf("CITY\n-%s\n",ptr[0].street);
    printf("STATE\n-%s\n",ptr[0].street);
    printf("CEP\n-%s\n",ptr[0].street);


}
