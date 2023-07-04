#include <bits/stdc++.h>
using namespace std;

vector<int> v;
stack<int> s;
vector<char> c;

int main(){
    int n,t;
    int v_idx=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    for(int i=1;i<=n;i++){
        s.push(i);
        c.push_back('+');
        while(v_idx<v.size()&&!s.empty()&&v[v_idx]==s.top()){
            s.pop();
            c.push_back('-');
            v_idx++;
        }
    }
    if(!s.empty()){
        cout<<"NO\n";
    }
    else{
        for(int i=0;i<c.size();i++){
            cout<<c[i]<<"\n";
        }
    }

}