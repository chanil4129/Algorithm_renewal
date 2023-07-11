#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}

int main(){
    int N;cin>>N;
    vector<pair<int,int>> v;
    int a,b;
    while(N--){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}