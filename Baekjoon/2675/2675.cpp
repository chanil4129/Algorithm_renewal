#include <iostream>
#include <string>
using namespace std;

int main(){
    int t; 
    cin>>t;
    int r;
    while(t--){
        cin>>r;
        string s;
        cin>>s;
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=0;j<r;j++){
                ans+=s[i];
            }
        }
        cout<<ans<<"\n";
    }
}