#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    char cs[1000];
    strcpy(cs,s.c_str());
    char *ptr=strtok(cs," ");
    vector<int> v;
    int max;
    int min;
    
    while(ptr!=NULL){
        v.push_back(atoi(ptr));
        ptr=strtok(NULL," ");
    }
    
    max=*max_element(v.begin(),v.end());
    min=*min_element(v.begin(),v.end());
    answer.append(to_string(min));
    answer.append(" ");
    answer.append(to_string(max));
    
    return answer;
}