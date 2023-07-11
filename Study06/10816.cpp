#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    int a;
    map<int,int> n;
    
    cin>>N;
    while(N--){
        cin>>a;
        n[a]++;
    }
    cin>>M;
    while(M--){
        cin>>a;
        cout<<n[a]<<" ";
    }
}