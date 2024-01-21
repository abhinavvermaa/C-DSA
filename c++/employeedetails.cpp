#include<stdio.h>
struct empd{
   int salary,empno,age;
   char name[10]; 
};
void printemp(struct empd obj[],int n){
    for(int i = 0;i<n;i++){
        printf("The name of employee %d is - ",obj[i].name);
        printf("The employee no. of employee %d is - ",obj[i].empno);
        printf("The salary of employee %d is - ",obj[i].salary);
        printf("The age of employee %d is - ",obj[i].age);
                    
    }
};
int main(){
    int n=2;
    struct empd obj[n];
    for(int i=0;i<n;i++){
        printf("enter the name of employee %d \n",i+1);
        scanf("%[^\n]s",obj[i].name);

        printf("enter the employee no. of employee %d \n",i+1);
        scanf("%d",&obj[i].empno);

        printf("enter the salary of employee %d \n",i+1);
        scanf("%d",&obj[i].salary);

        printf("enter the age of employee %d \n",i+1);
        scanf("%d",&obj[i].age);

    }
    printemp(obj,n);
    return 0;
}
