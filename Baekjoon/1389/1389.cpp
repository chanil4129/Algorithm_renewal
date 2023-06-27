#include <bits/stdc++.h>
using namespace std;

#define INF 123456789
#define VERMAX 111

int d[VERMAX][VERMAX];

int main(){
    int N,M,a,b;
    int min_weight=INF;
    int ans;
    cin>>N>>M;
    fill(&d[0][0],&d[VERMAX][VERMAX],INF);
    for(int i=0;i<VERMAX;i++){
        d[i][i]=0;
    }
    while(M--){
        cin>>a>>b;
        d[a][b]=1;
        d[b][a]=1;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N-1;j++){
            for(int k=j+1;k<=N;k++){
                d[k][j]=min(d[i][j]+d[i][k],d[k][j]);
                d[j][k]=d[k][j];
            }
        }
    }
    for(int i=1;i<=N;i++){
        int weight=0;
        for(int j=1;j<=N;j++){
            weight+=d[i][j];
        }
        if(min_weight>weight){
            min_weight=weight;
            ans=i;
        }
    }
    cout<<ans<<"\n";
}