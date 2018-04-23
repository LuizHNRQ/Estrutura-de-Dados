#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int num;
	struct Node* next;
} NodeE;

NodeE* startE(){
	return NULL;
}

int isEmptyE(NodeE* listE){

    if(listE == NULL){
    	printf("Empty\n");
        return 0;
    }
    return 1;
}

NodeE* memory_allocateE(NodeE *listE){

	NodeE *p = (NodeE*)malloc(sizeof(NodeE));

	if(p == NULL){
		return-1;
	}
	return p;
}

NodeE* insertE(NodeE *listE){

	int num;
    printf("Type the number to insert");
	scanf("%d", &num);

	NodeE *p = memory_allocateE(listE);
	p->num = num;

	if(listE == NULL){
		p->next = NULL;
		return p;
	}
	else {
		NodeE *prev = NULL, *act = listE;

		while((act != NULL)&&(act->num < num)){
														 														 ou o valor a ser insirido for menor ao da lista*/
			prev = act;
			act = act->next;
		}
		if (act == listE){
			p->next = listE;
			return p;
		} else {
            p->next = act;
			prev->next = p;
		}
		return listE;
	}

}

void searchBigE(NodeE *listE){

	NodeE* p = listE;
	int big;
	big = listE->num;
	if(isEmptyE(listE) == 0){
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

void searchSmallE(NodeE *listE){
	NodeE * p = listE;

	int small;
	small = listE->num;

	if(isEmptyE(listE) == 0){
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

NodeE *removeFirstE(NodeE *listE){
	NodeE *first;
	first = listE->next;

	if(isEmptyE(listE) == 0){
        return -1;
    }
     else {
		return first;
	}
}

NodeE *removeLastE(NodeE *listE){
	nodeE * last = listE;
	NodeE * penult = NULL;

	if(isEmptyE(listE) == 0){
        return -1;
    }
	if(last->next == NULL){
		return NULL;
	}else{
		while(last->next != NULL){
			penult = last;
			last = last->next;
		}
		if (last == NULL){
			return listE;
		}
		if(penult == NULL){
			listE = last->next;
		} else {
			penult->next = last->next;
		}
		free(last);
		return listE;
	}

}
void printE(NodeE *listE){

    NodeE* p = listE;

    if(isEmptyE(listE) == 0){
        printf("No element to exib\n");
    	return;
    } else {
	    while(p != NULL){
	        printf("%d \t", p->num);
	        p = p->next;
	    }
	}
}
