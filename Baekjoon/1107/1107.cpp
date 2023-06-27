#include <bits/stdc++.h>
using namespace std;

int N,M;
int b[10]; //가능한 버튼
string s; //목표 버튼
int c;
int ans;

bool f(string ch){
    for(int i=0;i<ch.length();i++){
        if(!b[ch[i]-'0'])
            return false;
    }
    return true;
}

int main(){
    int t;

    fill(b,b+sizeof(b)/sizeof(int),1);
    cin>>N>>M;
    s=to_string(N);
    while(M--){
        cin>>t;
        b[t]=0;
    }

    // 100번에서 이동
    ans=abs(N-100);

    // 번호 누르고 이동
    for(int i=0;i<1000000;i++){ //1000000는 0~??????까지 가능하므로
        string ch=to_string(i);
        if(f(ch)){
            c=abs(i-N)+ch.length(); // (+/- 버튼) + (숫자 버튼)
            ans=min(ans,c);
        }
    }
    cout<<ans<<"\n";
}