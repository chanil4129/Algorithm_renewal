#include<iostream>
#include<queue>
#include<functional>    //greater
using namespace std;

int N;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>x;
        if(x==0){
            if(pq.empty()) cout<<0<<"\n";
            else{
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }
        else pq.push({abs(x),x});
    }
}

//https://www.acmicpc.net/problem/11286