

#include<stdio.h>
#include<stdlib.h>

typedef struct people_info{

    char name[20];
    int age;
}people;


void bubbleSort(people array[], int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (array[j].age > array[j + 1].age) {
                aux  = array[j].age;
                array[j].age = array[j + 1].age;
                array[j + 1].age = aux;
            }
        }
    }
}

void print_array(people array[],int n){

int i;

for(i=0;i<n;i++){
    printf("Name =\t%s\t\t|Age =\t%d\n",array[i].name,array[i].age);
}
    printf("\n");
}

void print_array_decreasing(people array[],int n){

int i;

for(i=(n-1);i>=0;i--){
    printf("Name =\t%s\t\t|Age =\t%d\n",array[i].name,array[i].age);
}
    printf("\n");
}

int main(){

    people array[7]={{"Jessica",22},
    {"Lucas",24},{"Joseff",22},{"Johnny",38},{"Albert",20},
    {"Bernard",18},{"Guilher",31}};


int n = sizeof(array)/sizeof(array[0]);

print_array(array,n);

bubbleSort(array,n);

print_array(array,n);

print_array_decreasing(array,n);


return 0;
}
