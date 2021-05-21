#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char cFile[] = "date.txt";


struct bank
{
char id[10+1];
double process;
};



int search(char* user )/*判断帐号是否相同，不相同返回1*/
{
    FILE* file;
    char user_buff[256];
    file = fopen(cFile, "r");
    if (!file) return 0;
    while (!feof(file))
    {
        if (fscanf(file, "%s\n", user_buff) == EOF) return 0;
        if (!strcmp(user_buff, user))
        {
            return 1;
        }
    }
    fclose(file);
    return 0;
}


int add(char* user, double coin_n)
{
    FILE* file;
    file = fopen(cFile, "a");
    if (!file) return 0;
    fprintf(file, "%s  %.2lf\n", user,  coin_n);
    fclose(file);
    return 0;
}


int wenjian(char* user, double coin)
{
    if (search(user)) return 0;
    else add(user, coin);
    return 1;
}


int zhuce()/*注册*/
{
    struct bank *p;
    int i=0,k=0,judge1,judge2;
    char name[30];
	char event,ch;
	char sh[18];
	int n;
	p=(struct bank*)malloc(sizeof(struct bank));/*给p分配内存*/
    printf("请输入您所在地区(纯英文):");
	gets(name);
	printf("当天是否有事故(有事故请输入 1，无事故请输入 2):");
	fflush(stdin);
    scanf("%c",&event);
    fflush(stdin);
	printf("请输入您的身份证号码:");
	gets(sh);

	for(n=0;n<strlen(name);n++)/*判断输入信息是否正确*/
	{
		if(name[n]>='0'&&name[n]<='9')
		{
		printf("您输入的地区有误!\n");
		printf("\n请选择:按1返回主页面. 按任意键退出:");
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='1'){system("cls");int main();}
		else exit(0);
		 }
	}

	if(event!='1' && event!='2')/*判断输入信息是否正确*/
	{
	   printf("您输入的信息不对!\n");
	   printf("\n请选择:按1返回主页面. 按任意键退出:");
	   fflush(stdin);
	   scanf("%c",&ch);
		 fflush(stdin);
	   if(ch=='1'){system("cls");int main();}
	   else exit(0);
	}

	if(strlen(sh)!=18)/*判断输入信息是否正确*/
	{
	   printf("您输入的身份证号码不全!\n");
	   printf("\n请选择:按1返回主页面. 按任意键退出:");
		 fflush(stdin);
	   scanf("%c",&ch);
	   fflush(stdin);
	   if(ch=='1'){system("cls");int main();}
	   else exit(0);
	}

	for(n=0;n<strlen(sh)-1;n++)/*判断输入信息是否正确*/
	{
	   if(sh[n]<48||sh[n]>57)
	   {
		printf("您输入的身份证号码非法!\n");
		printf("\n请选择:按1返回主页面. 按任意键退出:");
		fflush(stdin);
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='1'){system("cls");int main();}
		else exit(0);
	   }

	   else
	   {
			if(sh[18]!='x'&&sh[18]<48&&sh[18]>57)
			{
			 printf("您输入的身份证号码非法!\n");
			 printf("\n请选择:按1返回主页面. 按任意键退出:");
			 fflush(stdin);
			   scanf("%c",&ch);
			   fflush(stdin);
			   if(ch=='1'){system("cls");int main();}
			   else exit(0);
			}
	   }

		}
    printf("请输入您的帐号(10位纯数字):\n");
    fflush(stdin);
    scanf("%s",p->id);
    fflush(stdin);
    while(i <strlen(p->id))
    {
        if((p->id[i] < 48) || (p->id[i] > 57))
        {
            judge1=0;
        }
        i++;
    }
    while(strlen(p->id)!=10 ||judge1==0)/*判断帐号的正确性*/
    {
        printf("您输入的帐号不正确，必须为10位纯数字！");
        printf("请重新输入(10位纯数字)：");
        fflush(stdin);
        scanf("%s",p->id);
        fflush(stdin);
    }

     printf("请输入事故处理所需步数:（一般事故处理需3步，特殊情况可输入更多步数）\n");
     fflush(stdin);
     scanf("%lf",&p->process);
     fflush(stdin);
     while((p->process)<3)
     {
          printf("事故处理至少需要三步，请重新输入:");
          fflush(stdin);
          scanf("%lf",&p->process);
          fflush(stdin);
     }
     if (wenjian(p->id,p->process))/*存入文件并输出基本信息*/
     {
          system("cls");
          printf("登记成功!");
          printf("您的事故信息如下,请牢记:\n");
          printf("地区:");
          puts(name);
          printf("事件代码:%c\n",event);
          printf("身份证号码:");
          puts(sh);
          printf("帐号:");
          puts(p->id);

          printf("事故剩余步数为:%.2lf\n",p->process);
          printf("请选择:按1返回主页面. 按任意键退出:");
          fflush(stdin);
    scanf("%c",&ch);
    fflush(stdin);
    if(ch=='1'){system("cls");int main();}
    else exit(0);
      }
      else/*如有相同帐号，注册失败*/
      {
          system("cls");
          printf("您输入的事故已经存在!登记失败!\n");
          printf("请选择:按1返回主页面. 按任意键退出:");
    scanf("%c",&ch);
       if(ch=='1'){system("cls");int main();}
    else exit(0);
      }
}


int gongneng(char Account[10+1],double process)/*登陆成功后的功能界面*/
{
		FILE *ps;
		struct bank xin[1000];
		int k=0,b=0;
		char mima[6+1],Chiose,x;
		char count[10+1],word[6+1];
		double inprocess,outprocess,addprocess;
		fflush(stdin);
		scanf("%c",&Chiose);
		fflush(stdin);
		ps=fopen(cFile,"r");
		if (!ps)
		{
		   printf("不能打开文件!按任意键退出!");
		   fflush(stdin);
		   scanf("%c",&x);
		   fflush(stdin);
		   exit(0);
		}
		if(Chiose=='1')
		{
			printf("输入您的处理成果:");
			fflush(stdin);
			scanf("%lf",&outprocess);
			fflush(stdin);
			while(!feof(ps))
			{
			  fscanf(ps, "%s %s %lf",&xin[k].id,&xin[k].process);
			  k++;
			}
			fclose(ps);
			ps=fopen(cFile,"wb");
			if (!ps)
			{
		   printf("不能打开文件!按任意键退出!");
		   fflush(stdin);
		   scanf("%c",&x);
		   fflush(stdin);
		   exit(0);
			}

			 while(!feof(ps))
			{
			   //printf("%s %s %.2lf\n",xin[b].id,xxin[b].process);
			   if ((strcmp(Account, xin[b].id)==0))
			   {
			   xin[b].process=xin[b].process-outprocess;
			   }
			   printf("%.2lf\n",xin[b].process);
			   fprintf(ps, "%s %s %.2lf\n", xin[b].id, xin[b].process);
			   b++;
			}
		}
}


int denglu()/*登陆*/
{
	FILE *fp;
	char account[10+ 1],h;
	int m=0;
	char real_account[10+ 1];         /* 帐号缓存 */
	double real_process_o=0.0;           /*事故状态缓存*/


	printf("请输入您的帐号(10位纯数字):");
	gets(account);
	fp = fopen(cFile, "r");


	if (!fp)
	{
	   printf("不能打开文件!按任意键退出!");
	   fflush(stdin);
	   scanf("%c",&h);
	   fflush(stdin);
	   exit(0);
	}
		while (m<=2) /*判断是否输入错3次了*/
		{

	while(fscanf(fp, "%s %s %lf", &real_account,&real_process_o) != EOF) /*循环判断帐号*/
		   {
				if (strcmp(real_account, account)==0)
				{
				system("cls");
				printf("登陆成功!");
					 gongneng(real_account,real_process_o);
					 fclose(fp);
					 return 0;
				}
			}

			rewind(fp); /*重新打开文件，进行新一轮的验证*/
			printf("您输入的帐号不存在!\n请重新输入:\n");
			m++;
			printf("请输入您的帐号(10位纯数字):");
			fflush(stdin);
			gets(account);
			fflush(stdin);

		}
		fclose(fp);
	printf("您输入帐号不正确已经3次,您被强制退出系统(按任意键退出)!");
		fflush(stdin);
	scanf("%c",&h);
	fflush(stdin);
	exit(0);
}


void Judge()//事故判定
{
	int people=0;
                int money=0;
	printf("请输入事故伤亡人数和财产损失：\n");
	printf("(注意：用空格做分割)\n");
	scanf("%d %d",&people, &money);
	if(people>=11)
	{
		printf("此事故为特大事故！！\n");
		 printf("处罚：吊销机动车驾驶证并处十日以上十五日以下拘留或者一百五十元以上二百元以下罚款。");
	}


	else if(people<=10 && people>=3)
	{
		if(money>=60000)
		{
			printf("此事故为特大事故！！\n");
			 printf("处罚：吊销机动车驾驶证并处十日以上十五日以下拘留或者一百五十元以上二百元以下罚款。");
		}
		else
		{
			printf("此事故为重大事故！\n");
			  printf("处罚：处十日以下拘留或者五十元以上一百五十元以下罚款并吊扣一个月以上六个月以下机动车驾驶证。");
		}

	}


	else if(people<=2 &&people>=1)
	{
		if(money>=60000)
		{
			printf("此事故为特大事故！！\n");
			 printf("处罚：吊销机动车驾驶证并处十日以上十五日以下拘留或者一百五十元以上二百元以下罚款。");
		}
		else if(money<=60000 && money>=30000)
		{
			printf("此事故为重大事故！\n");
			  printf("处罚：处十日以下拘留或者五十元以上一百五十元以下罚款并吊扣一个月以上六个月以下机动车驾驶证。");
		}
		else if(money<=30000 && money>=1000)
		{
			printf("此事故为一般事故\n");
			 printf("处罚：处五十元以下罚款或者警告并且吊扣一个月以上六个月以下机动车驾驶证。");
		}
		else if(money<=1000)
		{
			printf("此事故为轻微事故\n");
			 printf("处罚：处五十元以下罚款或者警告并且吊扣一个月以上六个月以下机动车驾驶证。");
		}
	}

	 else
        printf("WRONG");
     system("pause");
    printf("复议有关规定：");
    printf("当事人对公安交通管理部门作出的处罚不服\n");
    printf("可在接到处罚裁决书后15日内\n");
    printf("向上一级公安交通管理部门申请复议。\n");
    printf("当事人对交通事故责任认定不服\n");
    printf("可在接到认定书后15日内\n");
    printf("向上一级交警部门申请重新认定。\n");
}



int main()
{
    char chiose;

    printf("\n\n\t\t欢迎使用简易交通事故管理服务!\t\t\n\n");
    printf("请选择功能：\n");
    printf("\n=================================================\n");
    printf(" ||                请输入序号                  ||\n");
    printf(" ||               1.登记事故。                 ||\n");
	printf(" ||               2.查看事故状态。             ||\n");
	printf(" ||               3,事故处罚规定查询。         ||\n");
    printf(" ||               4.退出系统。                 ||\n");
    printf("=================================================\n");

    scanf("%c",&chiose);
    getchar();
    if(chiose <='0' ||chiose>='5')
    {
        while(chiose <='0' || chiose>='5')
        {
            printf("您的输入有误，请重新输入：");
            scanf("%c",&chiose);
            getchar();
        }
    }
    if(chiose=='1')
    {
        system("cls");
        zhuce();/*注册*/
    }
    if(chiose=='2')
    {
        system("cls");
        denglu();/*登陆*/
}
if(chiose=='3')
    {
        system("cls");
        Judge();//事故判定
    }

    if(chiose=='4')
    {
    printf("谢谢您的使用!");
    exit(0);
    }
}
