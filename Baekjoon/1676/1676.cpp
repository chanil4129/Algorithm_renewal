#include <bits/stdc++.h>
using namespace std;

int d[11]; //d[2]와 d[5]만 알면 되긴함..

//n는 a가 몇개로 이루어져 있나 확인하고 d[a]값 +해주기
void f(int n,int a){
    int res=0;
    while(n>1){
        if(n%a!=0){
            break;
        }
        n/=a;
        res++;
    }
    d[a]+=res;
}

int main(){
    int N;
    cin>>N;

    for(int i=1;i<=N;i++){
        f(i,2);
        f(i,5);
    }
    cout<<min(d[2],d[5])<<"\n";
}