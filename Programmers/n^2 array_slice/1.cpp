#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    pair<long long,long long> p;
    
    for(long long i=left;i<=right;i++){
        p.first=i/n;
        p.second=i%n;
        answer.push_back(max(p.first,p.second)+1);
    }
    
    return answer;
}