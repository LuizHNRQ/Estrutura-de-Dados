
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
