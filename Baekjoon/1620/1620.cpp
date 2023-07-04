#include <bits/stdc++.h>
using namespace std;

map<int,string> poketmon_int;
map<string,int> poketmon_str;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    string input;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>input;
        poketmon_int.insert({i,input});
        poketmon_str.insert({input,i});
    }
    for(int i=0;i<M;i++){
        cin>>input;
        if(input[0]>='0'&&input[0]<='9'){
            cout<<poketmon_int[stoi(input)]<<"\n";
        }
        else{
            cout<<poketmon_str[input]<<"\n";
        }
    }
}