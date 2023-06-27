#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int cnt=0;
    string s;
    cin>>N;

    for(int i=666;i<123456789;i++){
        s=to_string(i);
        if(s.find("666")!=string::npos){
            cnt++;
            if(cnt==N){
                cout<<i<<"\n";
                break;
            }
        }
    }
}