#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int,int>> v;
int ans;

bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}

int main(){
    cin>>N;
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),compare);
    int t=v[0].second;
    int ans=1;
    for(int i=1;i<v.size();i++){
        if(v[i].first>=t){
            ans++;
            t=v[i].second;
        }
    }
    cout<<ans<<"\n";
}