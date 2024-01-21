#include<stdio.h>

int main(){
    int i = 5;
    printf("the value after i++ is %d\n",++i);
    i++; // ---> pehle print fir increment
    ++i; //---> pehle increment fir print
    printf("the value after i is %d\n",i);
    i+=10;//--> increments i by 10
    printf("the value after i is %d\n",i);

    return 0;
}