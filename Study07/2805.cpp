#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long M;
    cin>>N>>M;
    long long a;
    vector<long long> v;
    for(int i=0;i<N;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.rbegin(),v.rend());
    long long left=0,right=v[0];
    long long mid;
    long long ans=0;
    while(left<=right){
        mid=(left+right)/2;
        long long ac=0;
        for(int j=0;j<v.size();j++){
            long long t=v[j]-mid;
            if(t>0){
                ac+=t;
            }
            else{
                break;
            }
        }
        if(ac>=M){
            ans=max(ans,mid);
            left=mid+1;
        }
        else{ //ac<M
            right=mid-1;
        }
    }
    cout<<ans<<"\n";
}