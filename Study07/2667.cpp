#include <bits/stdc++.h>
using namespace std;

int N;
int d[33][33];
vector<int> ans;
int dd[33][33];
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&d[i][j]);
        }
    }
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(d[i][j]&&!dd[i][j]){
                ans.push_back(1);
                q.push({i,j});
                dd[i][j]=1;
                while(!q.empty()){
                    pair<int,int> qf=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int n=qf.first+di[k];
                        int m=qf.second+dj[k];
                        if (0 <= n && n < N && 0 <= m && m < N && !dd[n][m] && d[n][m]){
                            ans[ans.size()-1]++;
                            q.push({n,m});
                            dd[n][m]=1;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        printf("%d\n",ans[i]);
    }
}