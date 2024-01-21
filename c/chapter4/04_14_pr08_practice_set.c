#include<stdio.h>

int main(){
    //prime number
    //this is not the best method to solve this problem
    int n=5,prime=1;
    for(int i=2;i<45;i++){
        if(n%i==0 ){
            prime= 0;
            break;
        }
    }
    if(prime==0){
        printf("this is not a prime number");
    }
    else{
        printf("this is a prime number");
    }
    return 0;
}