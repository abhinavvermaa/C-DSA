#include<stdio.h>
#include<math.h>

int main(){
    int a=4;
    int b=8;
    int z;
    z=a*b; //leagle
    //b*a=z; illeagle
    printf("the value of z is:%d\n",z);
    printf("the value of a+b is:%d\n",a+b);
    printf("the value of a-b is:%d\n",a-b);
    printf("the value of a*b is:%d\n",a*b);
    printf("the value of a/b is:%d\n",a/b);
    printf("5 when divided by 2 leaves an  remainder os %d\n",5%2);
    printf("-5 when divided by 2 leaves an  remainder os %d\n",-5%2);

    //no operator is assumed to be present
    // printf("the value of 4*5 is %d\n",(4)(5));/wrong
    printf("the value of 4*5 is %d\n",(4)*(5));
    printf("the value of 4^5 is %f\n",pow(4,5));

    printf("the value of 6+5 is %d\n",6+5);
    printf("the value of 6+5.6 is %f\n",6+5.6);
    printf("the value of 6.1+5.6 is %f\n",6.1+5.6);
    printf("the value of 5/2 is %d\n",5/2);
    printf("the value of 3.0/9 is %f \n",3.0/9);
    return 0;
}