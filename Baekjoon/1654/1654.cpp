#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int K,N,t;
    cin>>K>>N;
    while(K--){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    
    // 이분탐색
    long long left=1,right=v.back();
    long long mid;
    long long num;
    long long ans=0;
    while(left<=right){
        mid=(left+right)/2;
        num=0;
        for(int i=0;i<v.size();i++){
            num+=v[i]/mid;
        }
        if(num>=N){
            left=mid+1;
            ans=max(ans,mid);
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans<<"\n";
}