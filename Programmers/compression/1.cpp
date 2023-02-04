#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string,int> m;
    int idx;
    string st="";
    for(idx=1;idx<=26;idx++){
        char alpha=('A'+idx-1);
        st="";
        st+=alpha;
        m[st]=idx;
    }
    st="";
    for(int i=0;i<msg.size();i++){
        st+=msg[i];
        if(m.find(st)==m.end()){
            m[st]=idx++;
            if(st.size()!=1){
                i=i-1;
            }
            st.pop_back();
            answer.push_back(m[st]);
            st="";
        }
    }
    answer.push_back(m[st]);
    return answer;
}
