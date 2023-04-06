#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int d[27];
    memset(d,-1,sizeof(d));
    for(int i=0;i<s.length();i++){
        if(d[s[i]-'a']==-1)
            d[s[i]-'a']=i;
    }
    for(int i=0;i<26;i++){
        cout<<d[i]<<" ";
    }
}