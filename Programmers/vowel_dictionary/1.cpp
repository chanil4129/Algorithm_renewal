#include <string>
#include <vector>

using namespace std;

string s="";
vector<string> v{"A","E","I","O","U"};
int answer;
int cnt;

void dfs(string &word,int d){
    if(s==word){
        answer=cnt;
    }
    if(d>5){
        return;
    }
    cnt++;
    for(int i=0;i<5;i++){
        s+=v[i];
        dfs(word,d+1);
        s.pop_back();
    }
}

int solution(string word) {
    dfs(word,0);
    return answer;
}