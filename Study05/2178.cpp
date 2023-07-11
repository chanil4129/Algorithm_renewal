#include <bits/stdc++.h>
using namespace std;

int N,M;
int m[111][111];
int d[111][111];
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int main(){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&m[i][j]);
        }
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    d[1][1]=1;
    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int i=p.first+di[k];
            int j=p.second+dj[k];
            if (0 < i && i <= N && 0 < j && j <= M && m[i][j]==1 && d[i][j]==0){
                q.push({i,j});
                d[i][j]=1;
                m[i][j]=m[p.first][p.second]+1;
            }
        }
    }
    cout<<m[N][M]<<"\n";
}