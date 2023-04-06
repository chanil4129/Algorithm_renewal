#include <iostream>
#include <string>
using namespace std;

int main(){
    int t[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans+=t[s[i]-'A']+1;
    }
    cout<<ans;
}