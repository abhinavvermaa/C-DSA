#include<stdio.h>
void display();

int main(){
    int a;
    printf("intializing display function\n");
    display(); 
    printf("display function finished its work\n");
}

void display()
{
    int a;
    printf("enter a number\n");
    scanf("%d", &a);
    if(a>=45)
    {
        printf("the no is big\n");
    }
    else{
        printf("the no. is small");
    }
}