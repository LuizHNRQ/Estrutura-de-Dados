#include<stdio.h>
#include<stdlib.h>

typedef struct Node_C{
	int value;
	struct Node* next;
} NodeC;

NodeC* startC(){
	return NULL;
}



NodeC* memory_allocateC(NodeC *head){

	NodeC *p = (NodeC*)malloc(sizeof(NodeC));

	if(p == NULL){
		return -1;
	}
	return p;
}

void insertC(NodeC *head){
	int num;

	NodeC* act;
	*act= *head;

	printf("Type a num to insert =  ");
	scanf("%d", &num);

	NodeC *p =(NodeC*)malloc(sizeof(NodeC));

	p->num = num;

  	if (act == NULL){
     	p->next =p;
     	*head = p;
  	}
  	if (act->number >= p->number){
    	while(act->next != *head){
        act = act->next;
    	}

    	act->next = p;
	    p->next = *head;
	    *head = p;
  	}
  	else{
    	while ((act->next!= *head )&&(act->next->number)<(p->number)){
      		act = act->next;
    	}

    	p->next = act->next;
    	act->next = p;
    }
}

void searchBigC(NodeC* head){

	if(head == NULL){
		printf("EMPTY\n");
		return -1;
	}
    else {

    	int big = head->num;
    	NodeC * p = head;

		while(p->next != head){
			if(p->num > big){
				big = p->num;
			}
			p = p->next;
		}
		if(p->num > big){
				big = p->num;
		}
		printf("The biggest value = %d \n",big);

	}
}

void searchSmallC(NodeC *head){

	if(head == NULL){
		printf("EMPTY\n");
	}
	else{
    	int small;
    	small = head->number;
    	NodeC *p = head;

		while(p->next != head){
			if(p->number < small){
				small = p->number;
			}
                p = p->next;
		}
		if(p->number < small){
				small = p->number;
		}
		printf("The SMALL value = %d \n",small);
	}
}

NodeC* removeEndC(NodeC *head){

	if(head == NULL){
		printf("EMPTY\n");
	}
	else {
		NodeC * last = head;
    	NodeC * penult = head;

    	if(last->next == head){
    		free(last);
    		return NULL;
    	}
    	else {
    		while(last->next != head){
    			penult = last;
				last = last->next;
			}
    		penult->next = last->next;
    		free(last);
    	}
	}
	return head;
}

NodeC * removeStartC(NodeC *head){

	if(head == NULL){
		printf("EMPTY\n");
	}

	NodeC * start = head;
	NodeC * nextNodeC = head->next;

	if(start->next == head){
		return NULL;
	}
	else{

		while(start->next != head){
			start = start->next;
		}
		if (start == NULL){
			return head;
		}

		start->next = nextNodeC;
		free(head);
	}
	return nextNodeC;
}

NodeC* insertEndC(NodeC *head){

	int num;
	printf("Type the num = ");
	scanf("%d", &num);

	NodeC *p =(NodeC*)malloc(sizeof(NodeC));

	if(p == NULL){
		return -1;
	}

	p->num = num;

	if (head == NULL) {
		head = p;
		p->next = head;
		return p;
	}
	else {
		NodeC *endC = head;
		while(endC->next != head){
			endC = endC->next;
		}

		endC->next = p;
		p->next = head;
		return head;

	}
}
void printC(NodeC *head){
	if(head == NULL){
		printf("EMPTY\n");
	}
	else{
		NodeC *printNode = head;
		while(printNode->next != head){
			printf("%d\t", print->number);
			printNode = printNode->next;
		}
    printf("%d\t", printNode->number);
	}
}
