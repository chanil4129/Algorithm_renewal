#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}

int main(){
    int N;cin>>N;
    int a;
    vector<int> v;
    while(N--){
        cin>>a;
        v.push_back(a);
    }
    int d[8888];
    memset(d,0,sizeof(d));
    int ac=0;
    int mean;
    int median;
    int mode;
    int v_size;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ac+=v[i];
        d[v[i]+4000]++;
    }
    vector<pair<int,int>> dv;
    for(int i=0;i<=8001;i++){
        dv.push_back({i,d[i]});
    }
    
    sort(dv.begin(),dv.end(),cmp);
    mean=round((double)ac/(double)v.size());
    median=v[v.size()/2];
    mode=(dv[0].second==dv[1].second?dv[1].first:dv[0].first)-4000;
    v_size=v[v.size()-1]-v[0];
    cout<<mean<<"\n"<<median<<"\n"<<mode<<"\n"<<v_size<<"\n";
}