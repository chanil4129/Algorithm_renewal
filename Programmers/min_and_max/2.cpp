#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string token;
    istringstream iss(s);
    vector<int> v;
    int max,min;

    while(getline(iss,token,' ')){
        v.push_back(stoi(token));
    }

    max=*max_element(v.begin(),v.end());
    min=*min_element(v.begin(),v.end());
    answer=to_string(min)+" "+to_string(max);
    
    return answer;
}