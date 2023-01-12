#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> num_str;
    int n=0;
    vector<int> num_int;
    map<int,int> tup;
    
    num_str.push_back("");
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num_str[n]+=s[i];
        }
        else if(s[i]==','){
            n++;
            num_str.push_back("");
        }
    }
    for(int i=0;i<num_str.size();i++){
        num_int.push_back(stoi(num_str[i]));
        tup[num_int[i]]++;
    }
    vector<pair<int,int>> sort_tup(tup.begin(),tup.end());
    sort(sort_tup.begin(),sort_tup.end(),cmp);
    for(int i=0;i<sort_tup.size();i++){
        answer.push_back(sort_tup[i].first);
    }
    
    return answer;
}