#include <bits/stdc++.h>
using namespace std;

vector<int> n;
vector<int> m;

int main(){
    int N,M;
    int a;
    cin>>N;
    while(N--){
        cin>>a;
        n.push_back(a);
    }
    cin>>M;
    while(M--){
        cin>>a;
        m.push_back(a);
    }
    sort(n.begin(),n.end());

    //이분탐색
    int left,right;
    int mid;
    bool is_exist;
    for(int i=0;i<m.size();i++){
        is_exist=false;
        left=0;
        right=n.size()-1;
        while(left<=right){
            mid=(left+right)/2;

            if(n[mid]==m[i]){
                is_exist=true;
                cout<<"1\n";
                break;
            }
            else if(n[mid]>m[i]){
                right=mid-1;
            }
            else {//n[mid]<m[i]
                left=mid+1;
            }
        }
        if(!is_exist){
            cout<<"0\n";
        }
    }
}