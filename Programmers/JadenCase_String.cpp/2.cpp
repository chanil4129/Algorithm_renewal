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
    int pos;
        
    while(true){
        pos = s.find(" ");
        token = s.substr(0, pos);
        s=s.substr(pos+1);
        answer+=to_JadenCase(token);
        answer+=" ";
        
        if(pos==s.npos)
            break;
    }
    
    if(s.back()!=' ')
        answer.pop_back();
    
    return answer;
}