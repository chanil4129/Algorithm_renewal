#include <string>
#include <vector>

using namespace std;

int total;

void dfs(vector<int> &numbers, int &target,int sum,int n) {
    if(n >= numbers.size()){
        if(sum == target) total++;
        return;
    }

    dfs(numbers, target, sum + numbers[n], n+1);
    dfs(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(numbers, target, 0, 0);
    answer = total;
    return answer;
}