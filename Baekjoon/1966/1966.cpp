#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(int &a,int &b){
        return a<b;
    }
};

int main(){
    int T;cin>>T;
    
    while(T--){
        int N,M,t;
        priority_queue<int,vector<int>,cmp> pq;
        queue<pair<int,int>> q;
        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>t;
            q.push({i,t});
            pq.push(t);
        }
        int ans=1;
        bool is_end=false;
        while(!pq.empty()){
            int pq_top=pq.top();
            pq.pop();
            while(!q.empty()){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                if(b==pq_top){
                    if(a==M){
                        is_end=true;
                    }
                    break;
                }
                q.push({a,b});
            }
            if(is_end){
                cout<<ans<<"\n";
                break;
            }
            ans++;
        }
    }
}