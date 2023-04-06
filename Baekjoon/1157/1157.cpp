#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin>>s;
    int al[27]={0,};
    for(int i=0;i<s.length();i++){
        s[i]=toupper(s[i]);
        al[s[i]-'A']++;
    }
    int _max=0;
    int idx=0;
    for(int i=0;i<26;i++){
        if(_max<al[i]){
            _max=al[i];
            al[i]=0;
            idx=i;
        }
    }
    for(int i=0;i<26;i++){
        if(_max==al[i]){
            cout<<"?";
            return 0;
        }
    }
    cout<<(char)('A'+idx);
}