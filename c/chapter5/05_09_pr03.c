#include<stdio.h>
float force(float mass);

int main(){
    float m;
    printf("enter the value of mass in kgf\n");
    scanf("%f",&m);
    printf("the value of force in newton is %.2f\n",force(m));//decimal ke sath jitne digits chahiye ho toh usi ke hisab se %.1,2,3,4,f lgadena
    scanf("%f",&m);
    return 0;

    
    return 0;
}

float force(float mass){
    float result=mass*9.8;
    return result;
}