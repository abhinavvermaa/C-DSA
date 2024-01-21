#include<stdio.h>
void sumandavg(int x, int y, int *sum, float *avg);

int main(){
    int a,b,sum;
    float avg;
    printf("enter the value of a \n");
    scanf("%d", &a);
    printf("enter the value of b \n");
    scanf("%d", &b);
    sumandavg(a,b, &sum, &avg);
    printf("the sum of the number is %d\n", sum);
    printf("the average of the numbers is %f", avg);
    return 0;
}
void sumandavg(int x, int y, int *sum, float *avg){
     *sum = x+y;
     *avg = *sum/2;
}