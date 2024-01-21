#include<stdio.h>
#include<conio.h>
struct employee
{
    int id,age,salary;
    char name[25];
}emp[100];

void main()
{
    int i,n;
    printf("Enter the no of employees\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the details of employee - %d \n",i+1 );
        printf("Enter the name -\n");
        scanf("%s",emp[i].name);
        
        printf("Enter the id -\n");
        scanf("%d" , &emp[i].id);
        
        printf("Enter the age -\n");
        scanf("%d",&emp[i].age);
        
        printf("Enter the salary -\n");
        scanf("%d",&emp[i].salary);
    }
    printf("\nEMP_NAME\tEMP_ID\t\tEMP_AGE\t\tEMP_SALARY\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\n",emp[i].name,emp[i].id,emp[i].age,emp[i].salary);
    }
}
