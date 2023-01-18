#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer;                         //queue에 index 삽입
    vector<int> sorted;                         //정렬된 결과 저장용
    for(int i=0;i<priorities.size();i++){
        printer.push(i);
    }
    while(!printer.empty()){
        int idx=printer.front();
        printer.pop();
        if(priorities[idx]!=*max_element(priorities.begin(),priorities.end())){
            //아닌 경우
            printer.push(idx);
        }
        else{
            //맞는 경우
            sorted.push_back(idx);
            priorities[idx]=0;
        }
    }
    for(int i=0;i<sorted.size();i++){
        if(sorted[i]==location)
            return i+1;
    }
}