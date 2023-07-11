#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    vector<pair<int,int>> v;
    int a,b;
    while(N--){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}