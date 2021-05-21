#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main(){
    POINT mouse;
    system("title 456");
    while(1){
        GetCursorPos(&mouse);
        printf("%d,%d\n",mouse.x,mouse.y);
        Sleep(10);
        system("cls");
    }
}
/*    int a;
   for(;;){
    a=rand()%2;
    if(a==0)
        printf("//");
    Sleep(1);
    if(a==1)
        printf("\\");
   }*/

