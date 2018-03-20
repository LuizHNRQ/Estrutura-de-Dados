

// Luiz Henrique B T

//SO33A-ES31

//Create a File of a client and print the info
#include<stdio.h>
#include<stdlib.h>

int recursiveVector(int vector[],int length)
{
        if(length == 0)
            return 0;
        else
            return (vector[length-1] + recursiveVector(vector,length-1));
}
int main(){

int num,i;// num = Vector length || i = COUNTER

    printf("Type the vector length\n- ");
    scanf("%d",&num);

    int vector[num];//creates a victor with the inserted number length

    printf("Type the numbers to fill the vector\n\n");

    for(i=0;i<num;i++)
    {
    printf("  [%d] - ",i+1);//show the number the user is inserting || +1 for user friendly form
    scanf("%d",&vector[i]);
    }

    printf("\n\nThe sum of vector elements is = %d \n",recursiveVector(vector,num));//shows the result


};
