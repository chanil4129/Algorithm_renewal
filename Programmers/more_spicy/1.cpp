#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //기존 내가 했던 초기화..
    // priority_queue<int,vector<int>,greater<int>> pq;
    // for(int i:scoville){
    //     pq.push(i);
    // }
    priority_queue<int,vector<int>,greater<int>> pq (scoville.begin(),scoville.end());
    while(!pq.empty()){
        int n=pq.top();
        int s;
        
        if(n>=K){
            return answer;
        }
        pq.pop();
        if(pq.empty()){
            return -1;
        }
        s=pq.top();
        pq.pop();
        pq.push(n+2*s);
        answer++;
    }
    return answer;
}