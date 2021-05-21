#include<stdio.h>
int main()
{
    int a[6]={5,7,3,1,0,9};
    int min,i,j,t;
    for(j=0;j<5;j++)
    {
        min=j;
        for(i=j+1;i<6;i++)
        {
            if(a[i]<a[min])
                min=i;
        }
        if(min!=i)
        {
            t=a[j];
            a[j]=a[min];
            a[min]=t;
        }
    }
    for(i=0;i<6;i++)
    {
        printf("%d",a[i]);
    }
}
