#include <bits/stdc++.h>
using namespace std;

int N,r,c;
int ans;

void fun(int a, int b, int n){
    if(n==0) // 종료 조건
        return;

    int axis=(int)pow(2,n-1);
    int area=axis*axis;
    if(a<axis&&b<axis){ //1구역
        ans-=3*area;
        fun(a,b,n-1);
    }
    else if(a<axis){ //2구역
        ans-=2*area;
        fun(a,b-axis,n-1);
    }
    else if(b<axis){ //3구역
        ans-=area;
        fun(a-axis,b,n-1);
    }
    else{ //4구역
        fun(a-axis,b-axis,n-1);
    }
}

int main(void){
    cin>>N>>r>>c;
    ans=(int)pow(2,2*N)-1;
    fun(r,c,N);
    cout<<ans<<"\n";
}