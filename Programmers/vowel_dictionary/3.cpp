#include<bits/stdc++.h>
using namespace std;

int solution(string word) {
    int dp[6]={0,5};
    for(int i=2;i<=5;++i){
        dp[i]=5*(dp[i-1]+1);
    }
    string v="AEIOU";
    int ans=word.size();
    for(int i=0;i<word.size();++i){
        int p=v.find(word[i]);
        if(p)ans+=p*(1+dp[4-i]);
    }
    return ans;
}