#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    system("title 小数化为分数程序 - Created by FishLXY");
    char demical[100];
    double d_demical;
    int allDigit,demicalDigit;
    double dnumer,ddener;
    int numer,dener;
    int hcf;
    while(1)
    {
        printf("***小数化为分数程序***\n");
        printf("请输入小数：");
        gets(demical);
        d_demical=atof(demical);
        if(d_demical-(int)d_demical<1e-8)//判断是否为小数
        {
            printf(" error:请输入正确格式的小数！\n");
            system("pause");
            printf("\n");
            continue;
        }

        allDigit=strlen(demical)-1;//获取小数总位数
        demicalDigit=strlen(strstr(demical,"."))-1;//获取小数的小数部分位数

        dnumer=atof(demical)*pow(10,demicalDigit);//计算分子
        ddener=pow(10,(allDigit-1));//计算分母
        numer=dnumer;//转换为整数
        dener=ddener;
        Simplify(&numer,&dener);//化简

        if(numer>dener)
        {
            printf("化为假分数为：%d/%d\n",numer,dener);
            printf("化为带分数为：%d_%d/%d\n\n",numer/dener,numer-(numer/dener)*dener,dener);
        }
        else
            printf("化为分数为：%d/%d\n\n",numer,dener);
    }

}
int Simplify(int *num,int *den)//分数化简
{
    //分子分母同除最大公约数
    int hcf=Hcf(*num,*den);
    *num=*num/hcf;
    *den=*den/hcf;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int Hcf(int a,int b)//求最大公约数
{
    int c,d;
    while(1)
    {
      if(c!=0)
      {
        if(a>b)
            {c=a%b;a=c;d=b;}
        else if(a<b)
            {c=b%a;b=c;d=a;}
      }
      else if(c==1)
         return 1;
      else
         return d;
    }
}
