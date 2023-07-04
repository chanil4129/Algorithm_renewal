#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    vector<string> v;
    map<string,bool> m;
    vector<string> ans;
    cin>>N>>M;
    string s;
    while(N--){
        cin>>s;
        v.push_back(s);
    }
    while(M--){
        cin>>s;
        m.insert({s,true});
    }
    for(int i=0;i<v.size();i++){
        auto pos=m.find(v[i]);
        if(pos!=m.end()){
            ans.push_back(v[i]);
        }
    }
    cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}