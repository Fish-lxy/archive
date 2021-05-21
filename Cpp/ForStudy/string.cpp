#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1="12345";
    cout<<s1<<endl;

    string s2="abcde";
    string s3=s1+s2;
    cout<<s3<<endl;

    s1.insert(3,s2);
    cout<<s1<<endl;

    string s4="67890";
    s4.erase(2,3);
    cout<<s4<<endl;

    string s5="asdfghjkl";
    string s6=s5.substr(2,5);
    cout<<s6<<endl;
    cout<<s5.find("g",0)<<endl;
    cout<<s5.rfind("g",6)<<endl;
}
