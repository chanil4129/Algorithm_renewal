#include <string>
#include <vector>
#include <sstream>

using namespace std;

string to_JadenCase(string s){
    string result;
    
    for(int i=0;i<s.size();i++){
        result+=tolower(s[i]);
    }
    if(result[0]>='a'&&result[0]<='z'){
        result[0]-='a'-'A';
    }
    
    return result;
}

string solution(string s) {
    string answer = "";
    string token;
    stringstream ss(s);
    
    while(getline(ss,token,' ')){
        answer+=to_JadenCase(token);
        answer+=" ";
    }
    if(s.back()!=' ')
        answer.pop_back();
    
    return answer;
}