#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;cin>>N;
    string s;
    queue<int> q;
    while(N--){
        cin>>s;
        if(s=="push"){
            int X;
            cin>>X;
            q.push(X);
        }
        else if(s=="pop"){
            if(!q.empty()){
                cout<<q.front()<<"\n";
                q.pop();
            }
            else
                cout<<"-1\n";
        }
        else if(s=="size"){
            cout<<q.size()<<"\n";
        }
        else if(s=="empty"){
            if(q.empty())
                cout<<"1\n";
            else
                cout<<"0\n";
        }
        else if(s=="front"){
            if(!q.empty())
                cout<<q.front()<<"\n";
            else
                cout<<"-1\n";
        }
        else if(s=="back"){
            if(!q.empty())
                cout<<q.back()<<"\n";
            else
                cout<<"-1\n";
        }

    }
}