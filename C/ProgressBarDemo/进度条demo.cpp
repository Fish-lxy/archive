#include<cstdio>
#include<cstdlib>
#include<Windows.h>
//进度条DEMO
int main()
{
	printf("进度条DEMO\n");
	char bar[101] = {'\0'};
	for (int i = 0; i <= 50; i++)
	{
		printf("[%-50s]%3d%%", bar,i*2);
		bar[i] = '>';
		Sleep(50);
		putchar('\r');//光标移动到当前行行首
	}
	printf("\n");
	system("pause");
}
