#include <string>
#include <iostream>
#include <stack>
#define LEFT 0
using namespace std;

bool solution(string s)
{
    stack<int> st;
    
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='('){
            st.push(LEFT);
        }
        if(s.at(i)==')'){
            if(!st.empty() && st.top()==LEFT){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}