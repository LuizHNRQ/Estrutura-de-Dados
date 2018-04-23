
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node* next;
} Node;

int isEmptyList(Node * head){
	return (head == NULL);
}

Node * insert(Node* head, int value){
	Node *new = (Node*) malloc (sizeof(Node));
	new->value = value;
	if(isEmptyList(head)){
		head = new;
		new->next  = head;
		head->next = new;
	}
	else{
		new->next = head->next;
		head->next = new;
	}
	return head;
}

Node * removeList(Node* head){
	Node * p = head->next;
	Node * nextNode = head->next;
	if(head == NULL){
		return NULL;
	}
	else{
		while(p->next != head){
			p = p->next;
		}
		p->next = nextNode;
		free(head);
	}
	return nextNode;
}

void printListLoop(Node* head, int i){
	Node * p = head;
	if(isEmptyList(head)){
		printf("Essa lista está vazia!\n");
	}
	else{
		while(i > 0){
			printf("Valor: %d\n", p->value);
			p = p->next;
			i--;
		}
	}
}

void printList(Node* head){
	Node * p;
	p = head->next;
	if(isEmptyList(p)){
		printf("Essa lista está vazia!\n");
	}
	else{
		while(p != head){
			printf("Valor: %d\n", p->value);
			p = p->next;
		}
		printf("Valor: %d\n", p->value);
	}
}

//FUNÇAO DE REMOÇAO IMPLEMENTADA ->

void remove_element(Node *head, int element){

    Node *p = head;

    if( p == NULL)
        return 0;

    if(p->value == element){
        if( p == p->next){
            free(p);
            head ==NULL;
        }
        else{
            Node *last = p;
            while(last->next != NULL){
                last = last->next;
            }
            last->next = head->next;
            head = head->next;
            free(p);
        }
    }
    Node *prev = p;
    p = p->next;

    while(p != head && p->value != element){
        prev = p;
        p = p->next;
    }

    prev->next = p->next;
    free(p);

}

//FUNÇAO DE CALCULO DE MÉDIA IMPLEMENTADA ->

int calculate_avg(Node *head){

    Node *p = head;
    int avg_sum =0,count =0;

    p = head->next;

	if(isEmptyList(p)){
        printf("A lista esta vazia");
	}else{
		while(p != head){
			avg_sum += p->value;
			count++;

			p = p->next;
		}
		printf("Average: %d\n",(avg_sum/count));
	}

}


int main(){

	Node * head = NULL;
	printf("A lista esta vazia (0,1) : %d\n", isEmptyList(head));

	head = insert(head, 10);
	head = insert(head, 25);
	head = insert(head, 21);
	head = insert(head, 76);
	head = insert(head, 23);
	head = insert(head, 2);

	printf("Imprimindo a lista:\n");
	printList(head);
	calculate_avg(head);
	remove_element(head, 25);
    printf("Imprimindo a lista:\n");
	printList(head);
	calculate_avg(head);

	return 0;
}
