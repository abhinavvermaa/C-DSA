#include<stdio.h>

int main(){
    printf("****multiplication table of 10****\n\n");
    for(int i=1;i;i++){
        printf("10 X %d = %d\n", i , 10*i);
        if(i>9){
            break;
        }
    }
    return 0;
}