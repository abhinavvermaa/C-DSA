#include<stdio.h>

int main(){
    int i ;
    i = 3;
    int *j = &i;
    int **k = &j;
    printf ("the value of i is %d\n", (**k));
    return 0;
}