#include<stdio.h>
#include<stdlib.h>

typedef struct NodeD_E{
	int value;
	struct Node* next;
	struct Node* prev;
} NodeDE;

NodeDE* startDE(){
	return NULL;
}

int isEmptyDE(NodeDE* listDE){

    if(listDE == NULL){
    	printf("Empty\n");
        return 0;
    }
    return 1;
}

NodeDE *insertDE(NodeDE *listDE){
	int num;
	printf("Type the num to insert = ");
	scanf("%d",&num);

	NodeDE *p = (NodeDE*)malloc(sizeof(NodeDE));

	if(p == NULL){
		return-1;
	}
	p->num = num;

	if(listDE == NULL){
		p->next = NULL;
		p->prev = NULL;
		return p;
	}
	else{
		NodeDE *prev;
		NodeDE *act;
		*act = listDE;
		while(act != NULL && act->num<num){
			prev = act;
			act = act->next;
		}
		if (act == listDE){
			p->prev = NULL;
			listDE->prev = p;
			p->next = listDE;
			return p;
		}
		else {
			p->next = prev->next;
			p->prev = prev;

			prev->next = p;
			if(act != NULL){
				act->prev = p;
			}
		}
    return listDE;
	}
}


void searchBigDE(NodeDE *listDE){

	NodeDE* p = listDE;
	int big;
	big = listDE->num;
	if(isEmptyDE(listDE) == 0){
    	return -1;
    } else {
		while(p != NULL){

        if(p->num > big){
            big = p->num;
        }
			p = p->next;
		}
	}
	printf("The biggest value = %d \n",big);
}

void searchSmallDE(NodeDE *listDE){
	NodeDE * p = listDE;

	int small;
	small = listE->num;

	if(isEmptyDE(listDE) == 0){
        return -1;
    }
    else {
		while(p != NULL){
			if(p->num < small){
				small = p->num;
			}
			p = p->next;
		}
	}
	printf("The SMALL value = %d \n",small);
}

NodeDE *removeStartDE(NodeDE *listDE){

	NodeDE *start;
	*start = listDE->next;

	if(isEmptyDE(listDE) == 0){
    	return -1;
    	}
        else {
		return start;
        }
}

NodeDE * removeEndDE(NodeDE *listDE){

	NodeDE *last;
	*last = listDE;

	if(isEmptyDE(listDE) == 0){
    	return listDE;
    	}

	if(last->next == NULL){
		return NULL;
	}
	else{
		while(last->next != NULL){
                last = last->next;
		}

		last->prev->next = NULL;

		free(last);
		return listDE;
	}
}

NodeDE *insertEndDE(NodeDE *listDE){
	int num;

	NodeDE* last = listDE;
	printf("Type a num = ");
	scanf("%d", &num);

	NodeDE *p = (NodeDE*)malloc(sizeof(NodeDE));
	if(p == NULL){
		return -1;
	}

	p->number = number;
	p->next = listDE;
	p->prev = NULL;

	if(last->next == NULL){
		last->next = p;
		p->next = NULL;
		return listDE;
	}
	else{
		while(last->next != NULL){
        last = last->next;
		}

		last->next = p;
		p->next = NULL;
		return listDE;

	}

}
void printDE(NodeDE *listDE){

    NodeDE* p = listDE;

    if(isEmptyDE(listDE) == 0){
        printf("No element to exib\n");
    	return;
    } else {
	    while(p != NULL){
	        printf("%d \t", p->num);
	        p = p->next;
	    }
	}
}
