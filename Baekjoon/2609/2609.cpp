#include <bits/stdc++.h>
using namespace std;

int main(){
    int s1,s2;
    int a,b,c; //a>b
    cin>>s1>>s2;

    if(s1>s2){
        a=s1;
        b=s2;
    }
    else{
        a=s2;
        b=s1;
    }

    while(1){
        c=a%b;
        if(c==0){
            break;
        }
        a=b;
        b=c;
    }
    cout<<b<<"\n"<<s1*s2/b<<"\n";
}