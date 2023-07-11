#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;cin>>N>>K;
    int ans=1;
    for(int i=0;i<K;i++){
        ans*=N-i;
        ans/=i+1;
    }
    cout<<ans<<"\n";
}