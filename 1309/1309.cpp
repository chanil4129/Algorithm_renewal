#include <iostream>
using namespace std;

int N;
int d[100005];

int main(void){
    cin>>N;
    d[1]=3;
    d[2]=7;
    for(int i=3;i<=N;i++) d[i]=(2*d[i-1]+d[i-2])%9901;
    cout<<d[N];
}

//https://www.acmicpc.net/problem/1309