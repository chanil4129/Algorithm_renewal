#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    string operand="";
    vector<int> v;
    queue<char> q;
    int ans;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            operand+=s[i];
            continue;
        }
        v.push_back(stoi(operand));
        operand="";
        q.push(s[i]);
    }
    v.push_back(stoi(operand));

    ans=v[0];
    char op;
    bool minus=false;
    int ac=0;
    for(int i=1;i<v.size();i++){
        op=q.front();
        q.pop();
        if(op=='-'){
            if(!minus){
                ans+=ac;
                minus=true;
            }
            else{
                ans-=ac;
            }
            ac=v[i];
        }
        //op=='+'
        else{
            ac+=v[i];
        }
    }
    if(minus){
        ans-=ac;
    }
    else{
        ans+=ac;
    }
    cout<<ans<<"\n";
}