int elem_ordenated(Stack *s){

     Node * temp = s->top;

	if(isEmptyStack(s)){
		printf("Pilha vazia\n");
		return 0;
	}

	do{
        if(temp->value > temp->next->value){
            temp->value = temp->next->value;

        }
        else{
            return 0;
        }
	}while(temp->value > temp->next->value);

	return 1;
}

void prime_number(Stack *s){

    Node *temp;
    int i,div=0,prime_counter=0;

    for(temp=s->top;temp!=NULL;temp=temp->next){
        for(i=1;i<=temp->value;i++){
            if(temp->value % i == 0){
                div++;
            }
        }

        if(div==2){
            prime_counter++;
        }
    }

    printf("A Pilha tem %d Numeros primos \n",prime_counter);

}

int compare_Stack(Stack *s,Stack *x){

    Node *tempSs = s->top;
    Node *tempSx = x->top;

    if(tempSs->value == tempSx->value){

        while(tempSs->value == tempSx->value){
            tempSs = tempSs->next;
            tempSx = tempSx->next;
        }
        return 1;
    }
    else{
        return 0;
    }

}
