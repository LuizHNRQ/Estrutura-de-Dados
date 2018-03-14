// Luiz Henrique Barros Teixeira

//SO33A-ES31

/*

    In the main function create three variables calling as Square,A and Num and a cast naming Exp initializing as NULL.
    Make Exp receive adress of A. Ask the user a number and store in Num.


*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int math(int *square,int exp,int num){

*square = sqrt(num);

exp = num*num;

return exp;
}

int main(){

    int square = 0, A, num;
    int *exp = NULL;//Initializing as NULL

    exp = &A;

    printf("Type a number to assign to 'Num'\n");
    scanf("%d",&num);

    exp = math(&square,exp,num);

    printf("RESULT - square = %d | exp = %d ",square,exp,num);



return 0;
}
