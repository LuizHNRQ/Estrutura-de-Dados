
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node * next;
	struct Node * prev;
} Node;

typedef struct Queue{
	Node * start;
	Node * end;
} Queue;

Queue * create(){
	Queue * q = (Queue*) malloc(sizeof(Queue));
	q->start = NULL;
	q->end = NULL;
	return q;
}

void insertEnd(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->next = NULL;
	if(q->end != NULL){
		q->end->next = new;
		new->prev = q->end;
	}
	else{
		q->start = new;
		new->prev = NULL;
	}
	q->end = new;
}

void insertStart(Queue * q, int value){
	Node * new = (Node*) malloc(sizeof(Node));
	new->value = value;
	new->prev = NULL;
	if(q->end != NULL){
		q->start->prev = new;
		new->next = q->start;
	}
	else{
		q->end = new;
		new->next = NULL;
	}
	q->start = new;
}

int isEmptyQueue(Queue * q){
	return (q->start == NULL);
}

void printQueue(Queue * q){
	Node * p;
	p = q->start;
	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
	}
	else{
		while(p != NULL){
			printf("Valor: %d\n", p->value);
			p = p->next;
		}
	}
}

Node * search(Queue * q, int value){
	Node * p;
	for(p=q->start; p != NULL; p=p->next){
		if(p->value == value){
			return p;
		}
	}
	return NULL;
}

void freeQueue(Queue * q){
	Node * p = q->start;
	while(p != NULL){
		Node * t = p->next;
		free(p);
		p = t;
	}
	free(q);
}

int removeStartQueue(Queue * q){
	Node * t;
	int v;
	if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}
	t = q->start;
	v = t->value;
	q->start = t->next;
	if(t->next == NULL)
		q->end = NULL;
	else
		t->next->prev = NULL;
	free(t);
	return v;
}

int removeEndQueue(Queue * q){
	Node * t;
	int v;
	if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}
	t = q->end;
	v = t->value;
	q->end = t->prev;
	if(t->prev == NULL)
		q->start = NULL;
	else
		t->prev->next = NULL;
	free(t);
	return v;
}

int ordenated(Queue *q){

    Node *temp;
    if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}

	temp = q->end;

	if(temp->value > temp->prev->value){
        while(temp->value > temp->prev->value && temp->value != NULL){
            temp = temp->prev;
        }
        return 1;
	}
	else{
        return 0;
	}
}

void pairEnd(Queue *q){

    Node *temp = q->end;

    if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}

        if(temp->value%2==0){
            printf("O Valor PAR mais proximo do fim e' %d\n",temp->value);
        }
        else{
            while(temp->value%2!=0){
                temp->value = temp->prev->value;
                if(temp->value%2==0){
                printf("O Valor PAR mais proximo do fim e' %d\n",temp->value);
                }
            }
        }
}
void pairStart(Queue *q){

    Node *temp = q->start;

    if(isEmptyQueue(q)){
		printf("\nFila já vazia!\n");
		return 0;
	}

        if(temp->value%2==0){
            printf("O Valor PAR mais proximo do Inicio e' %d\n",temp->value);
        }
        else{
            while(temp->value%2!=0){
                temp->value = temp->next->value;
                if(temp->value%2==0){
                printf("O Valor PAR mais proximo do Inicio e' %d\n",temp->value);
                }
            }
        }
}

int CompareRecursive(Queue *q,Queue *qC){

    Node *temp1 = q->start;
    Node *temp2 = qC->start;

    if(temp1->value ==NULL || temp2->value ==NULL){
        return 0;
    }
    else{
        if(temp1->value == temp2->value){
            CompareRecursive(temp1->next->value,temp2->next->value);
            return 1;
        }else{
        return 0;
        }
    }
}

int main(){
	Queue * q;
	q = create();
	printf("Inserindo elemento 1 no início.\n");
	insertStart(q, 1);
	printf("Inserindo elemento 2 no início.\n");
	insertStart(q, 2);
	printf("Inserindo elemento 3 no início.\n");
	insertStart(q, 3);
	printf("Inserindo elemento 100 no fim.\n");
	insertStart(q, 100);
	printf("Inserindo elemento 99 no fim.\n");
	insertStart(q, 99);
	printf("Inserindo elemento 98 no fim.\n");
	insertStart(q, 98);
	printf("Imprimindo a fila:\n");
	printQueue(q);
	printf("Removendo um elemento do fim.\n");
	removeEndQueue(q);
	printf("Removendo um elemento do início.\n");
	removeStartQueue(q);
	printf("Imprimindo a fila:\n");
	printQueue(q);

	int ordenado;
    ordenado = printf("1 = Ordenado\n0=Desordenado\nR=%d\n",ordenated(q));

    pairEnd(q);
    pairStart(q);

    Queue * qC;
	qC = create();
    printf("\n---------SEGUNDA FILA-----------\nInserindo elemento 2 no início da segunda Fila.\n");
	insertStart(qC, 2);
	printf("Inserindo elemento 3 no início da segunda Fila.\n");
	insertStart(qC, 3);
	printf("Inserindo elemento 100 no fim da segunda Fila.\n");
	insertStart(qC, 100);
	printf("Inserindo elemento 99 no fim da segunda Fila.\n");
	insertStart(qC, 99);

	int iguais;
	iguais = printf("Iguais(0,1) = %d \n",CompareRecursive(q,qC));


	printf("Liberando a fila.\n");
	freeQueue(q);

	printf("Liberando a fila.\n");
	freeQueue(qC);
	return 0;
}
