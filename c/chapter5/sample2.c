#include<stdio.h>
void gm();
void gf();
void gn();


int main(){
    gm();
    return 0;
}

void gm(){
    printf("good morning\n");
    gf();
}
void gf(){
    printf("good afternoon\n");
    gn();
}
void gn(){
    printf("good night\n");
}