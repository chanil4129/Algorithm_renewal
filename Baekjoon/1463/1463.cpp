#include <bits/stdc++.h>
using namespace std;

int d[1234567];

int main(){
    int N;
    cin>>N;
    
    d[2]=1;
    d[3]=1;
    for(int i=4;i<=N;i++){
        d[i]=d[i-1]+1;
        if(i%3==0)
            d[i]=min(d[i],d[i/3]+1);
        if(i%2==0)
            d[i]=min(d[i],d[i/2]+1);
    }
    cout<<d[N]<<"\n";
}