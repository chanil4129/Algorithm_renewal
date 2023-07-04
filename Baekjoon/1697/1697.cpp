#include <bits/stdc++.h>
using namespace std;

int d[111111];

int main(){
    int N,K;
    int ans;
    cin>>N>>K;
    
    //N>=K
    for(int i=0;i<=N;i++){
        d[i]=N-i;
    }
    //N<K
    for(int i=N+1;i<=100000;i++){
        if(i%2==0){
            d[i]=min(d[i-1]+1,d[i/2]+1);
        }
        else{
            d[i]=min({d[i-1]+1,d[i/2]+2,d[(i+1)/2]+2});
        }
    }
    cout<<d[K]<<"\n";
}