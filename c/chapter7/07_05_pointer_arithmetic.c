#include<stdio.h>

int main(){
    // int i = 34;
    // int *ptr = &i;
    // printf("the value of  ptr is %u\n", ptr);
    // ptr--;
    // // ptr++;
    // printf("the value of  ptr is %u\n", ptr);   

    // char c = 34;
    // char *ptr = &c;
    // printf("the value of  ptr is %u\n", ptr);
    // ptr++;
    // ptr = ptr + 1;  
    // // ptr++;
    // printf("the value of  ptr is %u\n", ptr);

    float f = 3.4;
    float *ptr = &f;
    printf("the value of  ptr is %u\n", ptr);
    ptr++;
    ptr = ptr + 1;  
    // ptr++;
    printf("the value of  ptr is %u\n", ptr);    
    return 0;
}