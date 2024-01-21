#include<stdio.h>

int main(){
    //naive way to create 4 ints
    // int marks1, marks2, marks3, marks4;
    // marks1 = 34;
    // marks2 = 45;
    // marks3 = 67;
    // marks4 = 87;
    // in c language index  starts from 0;
    int marks[4];
    marks[0] = 34;
    marks[1] = 45;
    marks[2] = 67;
    marks[3] = 87;
    printf("%d %d %d %d", marks[0],marks[1],marks[2],marks[3]);
    return 0;
}