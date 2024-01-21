#include<stdio.h>
//sumis a function which takes a and b as input and return an integer as an output
int sum(int a,int b);//function prototype decleration

int main(){
    int c;
    c=sum(2,15);//function call{2,15}are arguments
    printf("the value of c is %d\n",c);
    return 0;
}
int sum(int a , int b ){//a, b are parameters
    int c;
    c= a+b;
    return c;
}