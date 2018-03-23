
#include<stdlib.h>
#include<stdio.h>

int square_search(int array[], int n, int x)
{
    int low = 0 , high = (n-1);

        while(low <= high && x >= array[low] && x <= array[high])
        {
            int position = low+(((float)(high-low))/((array[high]-array[low]))*(x-array[low]));

            if(array[position] == x )
                return position;

            if(array[position] < x )
                low = position +1;

            else{
                    high = position-1;
                }

        }

        return -1;
}


int main(){

 int array[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                 34, 55, 89, 144, 233, 377, 610 };

int n = sizeof(array)/sizeof(int);

int x = 55;

int index;

index = square_search(array, n, x);

printf("INDEX = %d ",index);


}
