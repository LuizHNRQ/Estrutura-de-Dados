

// Luiz Henrique B T

//SO33A-ES31

//Create a File of a client and print the info

#include<stdio.h>
#include<stdlib.h>

int menu();
void read(numCliFile);
void print(numCliFile);
void insertClients();

typedef struct Client{

    char name[50];
    char street[50];
    int  number;
    char city[30];
    char state[30];
    char cep[9];/* postal code */

}ClientFile;

ClientFile *ptr;

int numCliFile=0,newNum=0;

int main(){

char resp;

 insertClients();

 ptr = (ClientFile*)malloc(numCliFile*sizeof(ClientFile));

    read(numCliFile);

    do{
            switch(menu())
            {
            case 1:
                 insertClients();
                 ptr= (ClientFile*)realloc(ptr,newNum*sizeof(ClientFile));
                 read(newNum);
                break;
            case 2:
                print(numCliFile);
                break;
            default:printf("Invalid Value\n");return -1;
            }
            printf("\n[E]- To Exit \nPress any key to return MENU\n ");
            scanf("%c",&resp);

    }while(resp!='e'&&resp!='E');

    //print(numCliFile);

return 0;
}
void insertClients(){


printf("Type the number of new Clients File to insert\nNum = ");
scanf("%d",&newNum);

numCliFile+=newNum;
}

void read(int numCliFile){


   int i;//Counter

   for(i=1;i<=numCliFile;i++){


    printf("\t CLIENT FILE\n\n");
    printf("[%d]-Client\n",i);
    printf("Type the name\n- ");
    scanf("%s",&ptr[i].name);
    printf("Type the street\n- ");
    scanf("%s",&ptr[i].street);
    printf("Type the number\n- ");
    scanf("%d",&ptr[i].number);
    printf("Type the city\n-");
    scanf("%s",&ptr[i].city);
    printf("Type the state\n-");
    scanf("%s",&ptr[i].state);
    printf("Type the CEP\n-");
    scanf("%s",&ptr[i].cep);
    //system("cls");



   }

}
void print(int numCliFile){

   int i;//Counter

   for(i=0;i<=numCliFile;i++){

        printf("[%d]-Client\n",i);
        printf("NAME\n-%s\n",ptr[i].name);
        printf("STREET\n-%s\n",ptr[i].street);
        printf("NUMBER\n-%d\n",ptr[i].number);
        printf("CITY\n-%s\n",ptr[i].street);
        printf("STATE\n-%s\n",ptr[i].street);
        printf("CEP\n-%s\n",ptr[i].street);
        printf("---------------------\n");
   }



}

int menu(){

int opt;

printf("1 - Insert new Client file\n");
printf("2 - List all files\n\n");
printf("Type your option");
scanf("%d",&opt);

return opt;
}

