#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>&a, const pair<int,int> &b){
    if(a.second==b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for(int i=0;i<tangerine.size();i++){
        m[tangerine[i]]++;
    }
    vector<pair<int,int>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);
    while(k>0){
        k-=v[answer++].second;
    }
    return answer;
}