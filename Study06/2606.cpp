#include <bits/stdc++.h>
using namespace std;

#define INF 123456789

int main(){
    int n,m;
    int a,b;
    int d[111][111];
    cin>>n>>m;
    vector<pair<int,int>> v;
    fill(&d[1][1],&d[n][n],INF);
    for(int i=1;i<=n;i++){
        d[i][i]=0;
    }
    while(m--){
        cin>>a>>b;
        d[a][b]=1;
        d[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                d[j][k]=min(d[j][k],d[i][j]+d[i][k]);
                d[k][j]=d[j][k];
            }
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        if(d[1][i]!=INF){
            ans++;
        }
    }
    cout<<ans<<"\n";
}