#include<stdio.h>
int change(int y);


int main(){
    int x, temp;
    printf("enter the value of x ");
    scanf("%d", &x);
    printf("the value of y is %d\n", change(x));
    return 0;
}
int change(int y){
    y = y*10;
    return y;
}