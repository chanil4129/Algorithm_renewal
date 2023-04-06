#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        int ac=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='X')
                ac=0;
            else{
                ac++;
                ans+=ac;
            }
        }
        cout<<ans<<"\n";
    }
}