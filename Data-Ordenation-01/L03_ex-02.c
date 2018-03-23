

#include<stdlib.h>
#include<stdio.h>

void print_array(n,array);//function to print array

void bubble(int n, int array[]){
    int i, flag, aux=0, end = n,j,k;

    do{
      flag = 0;
        for(i=0;i<end-1;i++){

            if(array[i]>array[i+1]){
                aux = array[i];
                array[i] = array[i+1];
                array[i+1] = aux;
                flag = i;
            }
        }
    end--;
    }while(flag != 0);

}

int main(){

int array[] = { 50, 10, 1, 21, 33, 25, 98, 134};

int i,n = sizeof(array)/sizeof(int);

    print_array(n,array);

    bubble(n,array);

    print_array(n,array);

}
void print_array(int n,int array[]){

int i;

for(i=0;i<n;i++){
    printf("%d | ",array[i]);
}
printf("\n");

}
