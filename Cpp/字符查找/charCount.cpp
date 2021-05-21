#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int main(void)
{
    //统计输入的字母个数
    string s;
    cout<<"Please enter a string:"<<endl;
    cin>>s;
    int maxfreq=-1;
    int s_size=s.size();
    vector<int> freq(26);
    for(int i=0;i<s_size;i++){
        if(s[i]>='a'&&s[i]<='z')
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']>maxfreq)
                maxfreq=freq[s[i]-'a'];
    }
    for(int i=0;i<26;i++){
        char ch='a'+i;
        cout<<ch<<"="<<freq[i]<<' ';
    }
    cout<<'\n'<<maxfreq<<endl;
    system("pause");

}
