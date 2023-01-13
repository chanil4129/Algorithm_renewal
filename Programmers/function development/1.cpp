#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        int cnt=0;
        while(progresses[i]<100){
            progresses[i]+=speeds[i];
            cnt++;
        }
        if(!q.empty()) { //큐가 비어있지 않은 경우
            if(q.front()<cnt){ //뒷 작업이 늦게 끝나는 경우 => 바로 배포
                answer.push_back(q.size());
                q = queue<int>();
            }
        }
        q.push(cnt);
    }
    answer.push_back(q.size());

    return answer;
}