#include<stdio.h>

int main(){
    int phy, chem, maths; 
    float total;
    printf("enter physics marks\n");
    scanf("%d", &phy);
    printf("enter chemistry marks\n");
    scanf("%d", &chem);
    printf("enter maths marks\n");
    scanf("%d", &maths);
    total = (phy+maths+chem)/3;
    if((total<40) ||phy<33 || maths<33 || chem<33){
    printf("your total percentage is %f and you are fail\n", total);
    }
    else{
        printf("you total percentage is %f and you are pass\n", total);
    }                
    return 0;
}