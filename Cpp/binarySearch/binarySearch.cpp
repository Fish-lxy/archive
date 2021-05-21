#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
int main(void)
{
    vector<int> v;

    for(int i=0;i<10;i++)
        v.push_back(i);
    for(int i=0;i<10;i++)
        cout<<v[i]<<endl;
    cout<<endl;


    vector<int>::iterator v_head = v.begin();
    vector<int>::iterator v_end = v.end();
    vector<int>::iterator v_mid = v_head + (v_end - v_head)/2;
    int target;
    cin>>target;
    while(v_mid!=v_end&&(*v_mid)!=target){
        if(target<(*v_mid))
            v_end=v_mid;
        else
            v_head=v_mid+1;
        v_mid = v_head+(v_end-v_head)/2;
    }
    if(*v_mid==*v_end)
        cout<<"Not found"<<endl;
    else
        cout<<"Target is "<<*v_mid<<endl;
    system("pause");

}
