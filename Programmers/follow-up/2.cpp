#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int len=words.size();
    map<string,bool> h;

    h[words[0]]=true;
    for(int i=1;i<len;i++){
        if(h[words[i]] || (words[i-1][words[i-1].size()-1]!=words[i][0]))
            return {i%n+1,i/n+1};
        else
            h[words[i]]=true;
    }
    return {0,0};
}