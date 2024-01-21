#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number,guess,nguesses=1;
    srand(time(0));
    number = rand()%100 + 1;//generaate a random number from 1 to 100
    printf("the is number is %d \n", number);
    return 0;
}