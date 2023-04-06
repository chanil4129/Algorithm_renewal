#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
    int t; cin>>t;
    int al[27]={0,};
    int ans=0;
    while(t--){
        string s;
        cin>>s;
        memset(al,0,sizeof(al));
        int count=1;
        for(int i=0;i<s.length();i++){
            char k=s[i];
            if(al[k-'a']>=1){
                count=0;
                break;
            }
            al[k-'a']++;
            while(i<s.length()&&k==s[i+1])
                i++;
        }
        if(count) {
            ans++;
        }
    }
    cout<<ans;
}