#include<iostream>
#include<vector>

using namespace std;
int main(void)
{
    vector<int> v1;
    for(int i=0;i<10;i++){
        v1.push_back(i);
    }
    vector<int>::iterator b;
    for(b=v1.begin();b!=v1.end();++b){
        (*b)=(*b)*2;
    }
    for(b=v1.begin();b!=v1.end();++b){
        cout<<(*b)<<endl;
    }

}
