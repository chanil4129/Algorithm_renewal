#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int max=people.size()-1;
    int min=0;
    sort(people.begin(),people.end());
    while(min<=max){
        if(people[max]+people[min]<=limit){
            min++;
        }
        max--;
        answer++;
    }
    
    return answer;
}