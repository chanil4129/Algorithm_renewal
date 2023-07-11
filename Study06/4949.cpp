#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while (1){
        getline(cin,s);
        if (s == "."){
            break;
        }

        stack<char> st;
        bool is_right = true;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '(' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if (s[i] == ')'){
                    if (st.empty()||st.top() != '('){
                        is_right = false;
                        break;
                    }
                    st.pop();
                }
                else if (s[i] == ']'){
                    if (st.empty()||st.top() != '['){
                        is_right = false;
                        break;
                    }
                    st.pop();
                }
            }
        }
        if (is_right&&st.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }
}