#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for(int i=1;i<words.size();i++){
        //끝문자와 첫 문자 비교와 크기가 1보다 작은지
        if(words[i][0]!=words[i-1][words[i-1].size()-1]||words[i].size()<=1){
            answer[0]=i%n+1;
            answer[1]=i/n+1;
            return answer;
        }
        //단어 중복
        for(int j=0;j<i;j++){
            if(!words[i].compare(words[j])){
                answer[0]=i%n+1;
                answer[1]=i/n+1;
                return answer;
            }
        }
    }
    
    return {0,0};
}