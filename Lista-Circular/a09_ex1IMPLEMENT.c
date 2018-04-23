//APENAS AS FUNCOES

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
