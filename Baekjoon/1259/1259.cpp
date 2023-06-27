#include <bits/stdc++.h>
using namespace std;

int main(void){
    bool ans;
    string s;
    
    while(1){
        cin>>s;
        if(s=="0")
            break;

        ans=true;
        for(int i=0;i<s.length()/2;i++){
            if(s[i]!=s[s.length()-i-1]){
                ans=false;
                break;
            }
        }

        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";

    }
}