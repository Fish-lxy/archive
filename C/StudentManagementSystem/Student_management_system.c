#include<stdio.h>
#include<string.h>
struct Student{
    int num;
    float score;
    char name[10];
}stu[30],stu_Copied[30];//保存学生信息
int Command;//保存输入的指令
int Stu_num;//保存学生人数
float Stu_all_score=0;//保存所有学生的总分
float Stu_all_aver=0;//保存所有学生的平均分
int Greatnum=0,Goodnum=0,Middlenum=0,Passnum=0,Failnum=0;//保存分数等级个数
float Greatper=0,Goodper=0,Middleper=0,Passper=0,Failper=0;//保存分数等级百分比
int main()
{
    startScreen();
    inputCommand();
}
void startScreen()//开始屏幕
{
    printf("Management for Students' scores\n");
    printf("1.Input record\n");
    printf("2.Caculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by number\n");
    printf("5.Search by number\n");
    printf("6.Statistic analysis\n");
    printf("7.List record\n");
    printf("0.Exit\n");

}
void inputCommand()//指令输入处理
{
    while(1)
    {
        printf("Please Input your choice:");
        scanf("%d",&Command);
        switch(Command)
        {
            case 1:inputStu_num();inputStu_data();break;
            case 2:calAllstuScore();break;
            case 3:sortStuScore();break;
            case 4:sortStuNum();break;
            case 5:numGetStu();break;
            case 6:classifyStu();break;
            case 7:printfAll();break;
            case 0:exit(0);break;
            default:
                printf("Wrong command entered!\n");
        }
    }

}
void inputStu_num()//输入学生个数
{
    while(1)
    {
        printf("  Input student number(n<30):");
        scanf("%d",&Stu_num);
        if(Stu_num<30&&Stu_num>0)
            break;
        else
            printf("  Wrong data entered!\n");
    }

}
void inputStu_data()//输入学生信息
{
    printf("  Input student's ID name score:\n");
    for(int i=0;i<Stu_num;i++)
    {
        scanf("%d %s %f",&stu[i].num,stu[i].name,&stu[i].score);
        stu_Copied[i].num=stu[i].num;
        strcpy(stu_Copied[i].name,stu[i].name);
        stu_Copied[i].score=stu[i].score;
    }
}

void calAllstuScore()//计算学生的总分和平均分
{
    for(int i=0;i<Stu_num;i++)
    {
        Stu_all_score=Stu_all_score+stu[i].score;
    }
    Stu_all_aver=Stu_all_score/Stu_num;
    printf("  sum=%.0f,aver=%.2f\n",Stu_all_score,Stu_all_aver);
}
void sortStuScore()//对分数排序，排序后的学生信息保存到stu_Copied
{
    int i,j;
    int swapCount=Stu_num-1;
    float numtemp=0;
    float scoretemp=0;
    char nametemp[10];
    for(i=0;i<swapCount;i++)
    {
        for(j=0;j<swapCount-i;j++)
        {
            if(stu_Copied[j].score<stu_Copied[j+1].score)
            {
                numtemp=stu_Copied[j].num;
                stu_Copied[j].num=stu_Copied[j+1].num;
                stu_Copied[j+1].num=numtemp;

                scoretemp=stu_Copied[j].score;
                stu_Copied[j].score=stu_Copied[j+1].score;
                stu_Copied[j+1].score=scoretemp;

                strcpy(nametemp,stu_Copied[j].name);
                strcpy(stu_Copied[j].name,stu_Copied[j+1].name);
                strcpy(stu_Copied[j+1].name,nametemp);
            }
        }
    }
    printf("  Sort in descending order by score:\n");
    for(i=0;i<Stu_num;i++)
    {
        printf("   %d %s %.1f\n",stu_Copied[i].num,stu_Copied[i].name,stu_Copied[i].score);
    }
}
void sortStuNum()//对学号排序，排序后的学生信息保存到stu_Copied
{
    int i,j;
    int swapCount=Stu_num-1;
    float numtemp=0;
    float scoretemp=0;
    char nametemp[10];
    for(i=0;i<swapCount;i++)
    {
        for(j=0;j<swapCount-i;j++)
        {
            if(stu_Copied[j].num>stu_Copied[j+1].num)
            {
                numtemp=stu_Copied[j].num;
                stu_Copied[j].num=stu_Copied[j+1].num;
                stu_Copied[j+1].num=numtemp;

                scoretemp=stu_Copied[j].score;
                stu_Copied[j].score=stu_Copied[j+1].score;
                stu_Copied[j+1].score=scoretemp;

                strcpy(nametemp,stu_Copied[j].name);
                strcpy(stu_Copied[j].name,stu_Copied[j+1].name);
                strcpy(stu_Copied[j+1].name,nametemp);
            }
        }
    }
    printf("  Sort in ascending order by number:\n");
    for(i=0;i<Stu_num;i++)
    {
        printf("   %d %s %.1f\n",stu_Copied[i].num,stu_Copied[i].name,stu_Copied[i].score);
    }
}
void numGetStu()//输入学号查询学生信息
{
    int num,flag=0,i;
    printf("  Input student number:");
    scanf("%d",&num);
    for(i=0;i<Stu_num;i++)
    {
        if(num==stu[i].num)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("   %d %s %.1f\n",stu_Copied[i].num,stu_Copied[i].name,stu_Copied[i].score);
    else
        printf("Not found!\n");
}
void classifyStu()//按等级为学生分类
{
    for(int i=0;i<Stu_num;i++)
    {
        if(stu[i].score>=90)
            Greatnum++;
        else if(stu[i].score>=80&&stu[i].score<=89)
            Goodnum++;
        else if(stu[i].score>=70&&stu[i].score<=79)
            Middlenum++;
        else if(stu[i].score>=60&&stu[i].score<=69)
            Passnum++;
        else if(stu[i].score<=59)
            Failnum++;
    }
    Greatper=(Greatnum/(float)Stu_num)*100;
    Goodper=(Goodnum/(float)Stu_num)*100;
    Middleper=(Middlenum/(float)Stu_num)*100;
    Passper=(Passnum/(float)Stu_num)*100;
    Failper=(Failnum/(float)Stu_num)*100;
    printf("  Great(>=90) Number=%d Percentage=%.1f%%\n",Greatnum,Greatper);
    printf("  Great(80~89) Number=%d Percentage=%.1f%%\n",Goodnum,Goodper);
    printf("  Middle(70~79) Number=%d Percentage=%.1f%%\n",Middlenum,Middleper);
    printf("  Pass(60~69) Number=%d Percentage=%.1f%%\n",Passnum,Passper);
    printf("  Fail(<=60) Number=%d Percentage=%.1f%%\n",Failnum,Failper);
}
void printfAll()//输出全部学生信息
{
    for(int i=0;i<Stu_num;i++)
    {
        printf("  %3d %s  %3.1f\n",stu[i].num,stu[i].name,stu[i].score);
    }
}
