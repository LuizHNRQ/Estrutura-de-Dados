
// Luiz Henrique Barros Teixeira

//SO33A-ES31

//Create a doubly linked list and manipulate the data
#include<stdlib.h>
#include<stdio.h>


struct yt_channel{

    char channel_name[50];
    struct subscriber{

        char name[50];
        int age;
        struct subscriber *next;
    }subs;
    int total_vizualization;
    int number_videos;

    struct yt_channel *next;
    struct yt_channel *prev;

};
typedef struct yt_channel channel;


channel *start_list(){

return NULL;
}

channel *insert_elements(channel *L,int value){

    channel *new_channel = (channel*)malloc(sizeof(channel));

    if(!new_channel){
        return -1;
    }else{
    printf("Type the channel name:");
    scanf("%s",new_channel->channel_name);
    printf("Type the total of vizualization:");
    scanf("%d",&new_channel->total_vizualization);
    printf("Type the quantity of videos avaible:");
    scanf("%d",&new_channel->number_videos);
    channel->subs *new_subs = (channel->subs*)malloc(sizeof(channel->subs));
        if(!new_subs){
            return -1;
        }else{
          printf("Type the subscriber name:");
          scanf("%s",new_channel->subs.name);
          printf("Type the subscriber age:");
          scanf("%s",new_channel->subs.age);
          return new_subs;
        }

    return new_channel;
    new_channel->next = L;
    new_channel->prev = NULL;

    }



if(L != NULL){
    L ->prev = new_channel;
}

return new_channel;

}

int empty_list(channel *L){
    return(L ==NULL);
}

void print_list(channel *L){

    channel *temp;

    if(empty_list(L)){
        printf("\nERROR - Empty List\n");
    }
    else{
        for(temp=L;temp!=NULL;temp=temp->next){
            printf("Channel name:%s\nChannel Vizualizations:%d",temp->channel_name,temp->total_vizualization);
                printf("Channel number of videos:%d",temp->number_videos);
        }
        printf("\n");
    }


}

int find_big_element(channel *L){

    int i = 1,aux=0, pos;

    if( L == NULL || pos <=0)
        return 0;
    channel *temp = L;

    while(temp != NULL && i<pos){
        temp = temp->next;
        if(temp->next >= aux){
            aux = temp->next;
        }
        i++;
    }
    printf("Biggest Element = %d ",aux);

    if( temp == NULL)
        return 0;
    else{
        return 1;
    }

}
int find_small_element(channel *L){

    int i = 1,aux=0, pos;

    if( L == NULL || pos <=0)
        return 0;
    channel *temp = L;

    while(temp != NULL && i<pos){
        temp = temp->next;
        if(temp->next <= aux){
            aux = temp->next;
        }
        i++;
    }
    printf("Small Element = %d ",aux);

    if( temp == NULL)
        return 0;
    else{
        return 1;
    }

}

int insert_ordenate(channel *L){

    if(L==NULL)
        return 0;
    channel *temp;
    temp = (channel*)malloc(sizeof(channel));

    if(temp == NULL)
        return 0;
    if(temp == NULL){
        temp->next = NULL;
        temp->prev = NULL;
        L = temp;
        return 1;
    }
    else{
        channel *prev;
        channel *act = L;
        while(act != NULL){
            prev = act;
            act = act->next;
        }
        if(act == L){
            temp->prev = NULL;
            L->prev = temp;
            temp->next = L;
            L = temp;
        }else{
        temp->next = prev->next;
        temp->prev = prev;
        prev->next = temp;
        if(act != NULL){
            act->prev = temp;
        }
        return 1;
        }
    }

}

int insert_end(channel *L){

int aux;

    if(L ==NULL){
        return 0;
    }
    channel *temp;
    temp = (channel*)malloc(sizeof(channel));

    if(temp == NULL){
        return 0;
    }
    temp->next = NULL;
    if((temp)== NULL){
        temp->prev;
        L = temp;
    }else{
        channel *aux = L;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = temp;
        temp->prev = aux;
    }
return 1;
}

int remove_beguin(channel *L){

    if(L == NULL)
        return 0;

    channel *temp = L;
    L = temp->next;
    if(temp->next != NULL){
        temp->next->prev = NULL;
    }
    free(temp);
return 1;
}

int remove_end(channel *L){

    if(L == NULL)
        return 0;

    channel *temp = L;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev == NULL){
        L = temp->next;
    }else{
        temp->prev->next = NULL;
    }
    free(temp);
return 1;
}

int main(){

    int num_ch;
    channel *L;
    start_list(L);

    do{

    switch(menu())
    {
    case 1:
        printf("Type the number of channels to insert\n");
        scanf("%d",&num_ch);
        insert_elements(L,num_ch);
        break;
    case 3:
        find_big_element(L);
        break;
    case 4:
        find_small_element(L);
        break;
    case 5:
        insert_ordenate(L);
        break;
    case 6:
        insert_end(L);
        break;
    case 7:
        remove_beguin(L);
        break;
    case 8:

        break;
    default:printf("Wrong imput\n");

    }

    }while(menu()!=0);

return 0;
}

int menu(){

int option;

    printf("MENU YouTube\n\n1) adicionar canal\n");
    printf("3) encontrar o maior elemento\n");
    printf("4) encontrar o menor elemento\n");
    printf("5) inserir de forma ordenada\n");
    printf("6) inserir no fim de uma lista\n");
    printf("7) remover do início de uma lista\n");
    printf("8) remover do fim de uma lista;\n");

    printf("\nType your choise:");

    scanf("%d",&option);

return option;

}


