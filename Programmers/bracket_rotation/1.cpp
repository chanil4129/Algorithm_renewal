#include <string>
#include <vector>
#include <stack>

using namespace std;

bool right(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==']'){
            if(!st.empty()&&st.top()=='[')
                st.pop();
            else
                return false;
        }
        else if(s[i]=='}'){
            if(!st.empty()&&st.top()=='{')
                st.pop();
            else
                return false;
        }
        else if(s[i]==')'){
            if(!st.empty()&&st.top()=='(')
                st.pop();
            else
                return false;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.size();i++){
        string b="";
        if(right(s)){
            answer++;
        }
        b=s.substr(1);
        b+=s[0];
        s=b;
    }
    return answer;
}