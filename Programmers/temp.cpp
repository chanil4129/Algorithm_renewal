#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_set>

using namespace std;

int main(void){
    string s="{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> answer;
    vector<string> num_str;
    int n=0;
    vector<int> num_int;
    unordered_set<int> tup;
    
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
        cout<<num_str[i]<<"\n";
    }
    // for(int i=0;i<num_str.size();i++){
    //     int t;
    //     t=stoi(num_str[i]);
    //     num_int.push_back(t);
    //     tup.insert(num_int[i]);
    // }
    for(const auto& e : tup){
        answer.push_back(e);
    }
    
    return 0;
}