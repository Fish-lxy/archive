#include<iostream>
using namespace std;
int main(void)
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    int *a_head=begin(a);
    int *a_end=end(a);
    cout<<*a_head<<endl;
    cout<<*(--a_end)<<endl;
}
