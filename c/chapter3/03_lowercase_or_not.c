#include<stdio.h>

int main(){
    char ch;
    //97-122 = a-z (ASCII values)
    printf("enter the character \n");
    scanf("%c",&ch);
    if(ch<=122&& ch>=97){
        printf("It is lowercase");
    }
    else {
        printf("it is uppercase");
    }
    return 0;
}