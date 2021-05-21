#include<cstdio>
#include<climits>
int reverseInt(int x);
int getDivisorCount(long long x);
int main(void){
    printf("%d\n",getDivisorCount(1200000));
    printf("%d",reverseInt(12345));
}
int reverseInt(int x){//数字反转
    int result=0;
    int pop=0;
    while(x!=0){
        pop=x%10;
        x=x/10;
        if (result > INT_MAX/10 || (result == INT_MAX / 10 && pop > 7))
            return 0;
        if (result < INT_MIN/10 || (result == INT_MIN / 10 && pop < -8))
            return 0;
        result=result*10+pop;
    }
    return result;
}
int getDivisorCount(long long x){//求约数个数
    int result=0;
    for(long long i=1;i<=x;i++){
        if(x%i==0){
            ++result;
        }
    }
    return result;
}
