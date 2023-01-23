#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    int n[123456789];
    q.push(0);
    for(int i=0;i<numbers.size();i++){
        int count=0;
        while(!q.empty()){
            n[count]=q.front();
            count++;
            q.pop();
        }
        for(int j=0;j<count;j++){
            q.push(n[j]+numbers[i]);
            q.push(n[j]-numbers[i]);
        }
    }
    while(!q.empty()){
        if(q.front()==target)
            answer++;
        q.pop();
    }
    return answer;
}