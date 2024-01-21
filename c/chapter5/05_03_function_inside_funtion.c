#include<stdio.h>
void goodmorning();
void goodafternoon();
void goodnight();


int main(){
    goodmorning();

    return 0;
}

void goodmorning()
{
    printf("good morning avi\n");
        goodafternoon();

}
void goodafternoon()
{
    printf("good afternoon avi\n");
        goodnight();

}
void goodnight()
{
    printf("good night avi\n");
}