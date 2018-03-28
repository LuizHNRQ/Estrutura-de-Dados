// Luiz Henrique Barros Teixeira

//SO33A-ES31

//Create a threaded list and manipulate the data

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int menu();

struct Node{

    int ep_num;
    int ep_time;
    char ep_name[50];
    struct Node *prox;


};
typedef struct Node node;

void start_node(node *LIST){

LIST->prox = NULL;

}

node *allocate(){

    node *new_node = (node*)malloc(sizeof(node));
    if(!new_node){
        return -1;
    }else{
        printf("New episode = ");
        scanf("%d",&new_node->ep_num);
        return new_node;
    }


}

void insert_episode(node *LIST){

    node *new_ep=allocate();
    node *oldNode = LIST->prox;

    LIST->prox = new_ep;
    new_ep->prox = oldNode;

}

int isEmptyList(node *LIST){
    return(LIST == NULL);
}

void print_node(node *LIST){

    node *temp = LIST;

    if(isEmptyList(temp)){
        printf("Empty list\n");
        return -1;
    }else{
        for(temp = LIST; temp!=NULL ; temp = temp->prox){
            printf("EPISODE = %d | Duration = %d\n ",temp->ep_num,temp->ep_time);
        }

    }

}

void print_node_recursive(node *LIST){

    node *temp = LIST;

    if(isEmptyList(temp)){
        printf("Empty list\n");
        return -1;
    }else{
        while(temp != NULL){
            printf("EPISODE = %d | Duration = %d\n ",temp->ep_num,temp->ep_time);
            temp = temp->prox;
        }

    }

}

void print_node_recursive_reverse(node *LIST){

    node *temp = LIST;

    if(isEmptyList(temp)){
        printf("Empty list\n");
        return -1;
    }else{
        while(temp != NULL){
            temp = temp->prox;
            printf("EPISODE = %d | Duration = %d\n ",temp->ep_num,temp->ep_time);
        }

    }

}

node *search_remove(node *LIST,char compare[50]){

    node *temp = LIST;
    node *remove = NULL;

    for(temp = LIST; temp != NULL ; temp = temp->prox){
        if(strcmp(temp->ep_name,compare)== 0){
            remove = temp;
            temp = temp->prox;

            if(temp = NULL){
                return LIST;
            }else{
                remove->prox = temp->prox;
            }
            free(temp);
            printf("EPISODE REMOVED\n");
            return LIST;

        }
    }


}
node *search_print(node *LIST,char compare[50]){

    node *temp = LIST;

    for(temp = LIST; temp != NULL ; temp = temp->prox){
        if(strcmp(temp->ep_name,compare)== 0){
            printf("EPISODE = %d | NAME = %s | DURATION = %d\n",temp->ep_num,temp->ep_name,temp->ep_time);

        }else{
            printf("No episode has been found\n");
        }
    }


}

node * search_duration(node *LIST,int duration){

    node * temp;

    for(temp=LIST;temp!=NULL;temp = temp->prox){
        if(duration == temp->ep_time){
            printf("EPISODE = %d | NAME = %s | DURATION = %d\n",temp->ep_num,temp->ep_name,temp->ep_time);
        }else{
            printf("No episode has been found by this duration\n");
        }
    }

}

void freeLIST(node *LIST){

    node *temp = LIST;

    while(temp != NULL){
        node * next = temp->prox;
        free(temp);
        temp = next;
    }
}

int main(){

int duration_search;
char ep_name_compare[50];

node *LIST = (node*) malloc(sizeof(node));

    do{

    switch(menu())
    {
    case 1:

        if(!LIST){
         return -1;
        }else{
        start_node(LIST);
        }
        break;
    case 2:
        insert_episode(LIST);
        break;
    case 3:
        print_node(LIST);
        break;
    case 4:
        print_node_recursive(LIST);
        break;
    case 5:
        print_node_recursive_reverse(LIST);
        break;
    case 6:
        printf("Type the name of Episode to REMOVE\n");
        scanf("%s",&ep_name_compare);
        search_remove(LIST,ep_name_compare);
        break;
    case 7:
        printf("Type the name of Episode to SEARCH\n");
        scanf("%s",&ep_name_compare);
        search_print(LIST,ep_name_compare);
        break;
    case 8:
        printf("Type the duration of Episode to SEARCH\n");
        scanf("%d",&duration_search);
        search_duration(LIST,duration_search);
        break;
    case 9:
        freeLIST(LIST);
        break;
    }

    }while(menu()!=9);

return 0;
}

int menu(){

int opc;

    printf("BETTER CALL SAUL MENU\n\n[1]-Start List \n[2]-Insert episode \n[3]-print ");
    printf("\n[4]-print recursive \n[5]-print recursive reverse  \n[6]-remove episode by name ");
    printf("\n[7]-Search episode by name \n[8]-Search episode by duration \n[9]-Free the list \n\nOPTION:");

    scanf("%d",&opc);

return opc;
}
