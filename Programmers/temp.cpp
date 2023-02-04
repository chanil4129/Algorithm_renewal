#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

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
    for(auto iter:m){
        cout<<iter.first<<" "<<iter.second<<"\n";
    }
    for(int i=0;i<msg.size();i++){
        st+=msg[i];
        for(int j=i+1;j<msg.size();j++){
            st+=msg[j];
            cout<<"DIC : "<<st<<"\n";
            if(m.find(st)==m.end()){ //사전에 없는 경우
                m[st]=idx++;
                st.pop_back();
                answer.push_back(m[st]);
                st="";
                i=j-1;
                break;
            }
        }
    }
    cout<<st<<"\n";
    answer.push_back(m[st]);
    for(auto iter:m){
        cout<<iter.first<<" "<<iter.second<<"\n";
    }
    return answer;
}

int main(void){
    solution("TOBEORNOTTOBEORTOBEORNOT");
}