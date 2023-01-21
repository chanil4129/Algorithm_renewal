#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int,int>&a, const pair<int,int> &b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for(int i=0;i<tangerine.size();i++){
        m[tangerine[i]]++;
    }
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(),cmp);
    for (int i = 0; i < v.size(); i++){
        cout << v[i].second << '\n';
    }
    while (k > 0){
        k -= v[answer++].second;
    }
    return answer;
}


int main(){
    vector<int> t{1,3,2,5,4,5,2,3};
    solution(6,t);
}