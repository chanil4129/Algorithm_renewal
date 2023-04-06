#include <iostream>
#include <limits.h>
using namespace std;

int N; //인원수
int s[22][22]; //스탯 저장 테이블
bool v[22]; //true인 팀과 false인 팀 두부류
int ans=INT_MAX; //정답

void f(int team, int depth){ //team : 한쪽팀 인원 수,  depth : 깊이
    if(depth>N) return; //깊이 넘으면 종료
    if(team==N/2){ //N/2명씩 팀이 정해졌을 때
        int stat1=0; //1팀 스탯
        int stat2=0; //2팀 스탯
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++){ //각 팀 스탯 계산
            if(v[i]&&v[j]) stat1+=s[i][j];
            if(!v[i]&&!v[j]) stat2+=s[i][j];
        }
        ans=min(ans,abs(stat1-stat2)); //ans 최솟값 저장
        return;
    }
    //true팀
    v[depth]=true;
    f(team+1,depth+1);
    //fasle팀
    v[depth]=false;
    f(team,depth+1);
}

int main(void){
    cin>>N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin>>s[i][j];
    f(0,1);
    cout<<ans;
}

//https://www.acmicpc.net/problem/14889