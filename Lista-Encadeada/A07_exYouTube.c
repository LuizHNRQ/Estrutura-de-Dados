// Luiz Henrique Barros Teixeira

//SO33A-ES31

//Create a threaded list of a youtube channel 

#include<stdlib.h>
#include<stdio.h>

int menu();

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

};
typedef struct yt_channel channel;

void start_channel_node(channel *channel_info){

    channel_info->next = NULL;
}

void start_channel_node_subs(channel->subs *channel_subs_info){

    channel_subs_info->next = NULL;

}

channel *allocate(){

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
    }

}

int isEmptyChannel(channel *channel_info){
    return(channel_info == NULL);
}

void insert_channel(channel *channel_info){

    channel *new_channel=allocate();
    channel *prev_channel = channel_info->next;

    channel_info->next = new_channel;
    new_channel->next = prev_channel;


}
void print_channel(channel *channel_info){

    channel *temp =channel_info;

        if(isEmptyChannel(temp)){
            printf("Empty Channel List");
        }else{
            for(temp = channel_info; temp != NULL; temp = temp->prox){
                printf("Channel name:%s\nChannel Vizualizations:%d",temp->channel_name,temp->total_vizualization);
                printf("Channel number of videos:%d",temp->number_videos);
            }

        }


}

int search_bigVizualization(channel *channel_info){

    int big = channel->total_vizualization;
    channel *temp = channel_info;

    while(temp !=NULL){
        if(temp->total_vizualization > big){
            big = temp->total_vizualization;
        }
        temp = temp->next;
    }
    return big;
}
int search_smallVizualization(channel *channel_info){

    int small = channel->total_vizualization;
    channel *temp = channel_info;

    while(temp !=NULL){
        if(temp->total_vizualization < small){
            small = temp->total_vizualization;
        }
        temp = temp->next;
    }
    return small;
}

channel *removeLastChannel(channel *channel_info){

    if(isEmptyChannel(channel_info)){
        return NULL;
    }else{
        channel * last = channel_info->next;
        channnel *penultimate = channel_info;

        while(last->next != NULL){
            penultimate = last;
            last = last->next;
        }
        penultimate->next = NULL;
        free(last);
        return channel_info;
        }

}

channel *removeStartChannel(channel *channel_info){

    if(isEmptyChannel(channel_info)){
        return NULL;
    }else{
        channel *aux = channel_info;
        channel_info = aux->next;
        free(aux);
        return channel_info;
        }

}
void num_Subs(channel *channel_info){

int num_subs=0;

    channel->subs *temp_subs =channel_info->subs;

        if(isEmptyChannel(temp_subs)){
            printf("Empty Subs List");
        }else{
            for(temp_subs = channel_info->subs; temp_subs != NULL; temp_subs = temp_subs->prox){
                num_subs++;
            }
        printf("Channel name:%s\n",temp_subs->channel_name);
        printf("Number of Subscriber: %d\n",num_subs);
        num_subs=0;

        }


}

int main(){

    channel *channel_info =(channel*)malloc(sizeof(channel));
    channel->subs *channel_subs =(channel->subs*)malloc(sizeof(channel->subs));

    do{

    switch(menu())
    {
    case 1:
            if(!channel_info){
                return -1;
            }else{
            start_channel_node(channel_info);
            insert_channel(channel_info);
                }
            break;
    case 2:
        print_channel(channel_info);
        break;
    case 3:
        search_bigVizualization(channel_info);
        break;
    case 4:
        search_smallVizualization(channel_info);
            break;
    case 5:
        channel_info = removeLastChannel(channel_info);
        break;
    case 6:
        channel_info = removeStartChannel(channel_info);
        break;
    case 7:
        num_Subs(channel_info);
        break;
    default:printf("Wrong imput\n");

    }

    }while(menu()!=0);

return 0;
}

int menu(){

int option;

    printf("MENU YouTube\n\n1) adicionar canal\n");
    printf("2) listar todos os canais\n");
    printf("3) mostrar canal com o maior quantidade de visualizações\n");
    printf("4) mostrar canal com menor quantidade de visualizações\n");
    printf("5) remover o último canal da lista\n");
    printf("6) remover o primeiro canal da lista\n");
    printf("7) mostrar a quantidade de inscritos de cada canal\n");
    printf("\nType your choise:");

    scanf("%d",&option);

return option;

}
