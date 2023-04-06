#include <iostream>
#include <string>
using namespace std;

int f(string &s){
    char t;
    t=s[0];
    s[0]=s[2];
    s[2]=t;
    return stoi(s);
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    cout<<max(f(s1),f(s2));
}