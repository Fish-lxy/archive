#include<stdio.h>
#include<windows.h>
int main(){
//----------------------------------------------------------------------------
        //计时代码部分，精度微秒级
    double run_time;
    LARGE_INTEGER time_start;	//开始时间
    LARGE_INTEGER time_over;	//结束时间
    double dqFreq;		//计时器频率
    LARGE_INTEGER f;	//计时器频率
    QueryPerformanceFrequency(&f);
    dqFreq = (double)f.QuadPart;
    QueryPerformanceCounter(&time_start); 
    //计时开始
//----------------------------------------------------------------------------
    for(int i=0;i<10;i++){
        printf("Hello,world!\n");

    }

//----------------------------------------------------------------------------
    //计时结束
    QueryPerformanceCounter(&time_over);
    run_time = 1000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
    //乘以1000把单位化为毫秒
    printf("\ntime:%.4lfms\n", run_time);
    //----------------------------------------------------------------------------

}
