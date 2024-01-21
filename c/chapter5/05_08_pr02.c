#include<stdio.h>
float temprature(int c);

int main(){
    float d;
    printf("enter the value of temprature in celsius \n");
    scanf("%f",&d);
    printf("the value of temprature in celsius is %f",temprature(d));
    
    return 0;
}

float temprature(int c){
    float result;
    result=(float)(c*1.8)+32;
    return result;
}