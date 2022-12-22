#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string b="";
    answer.push_back(0);
    answer.push_back(0);
    
    while(s.compare("1")){
        int len;
        b="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                b+="1";
            }
            else if(s[i]=='0'){
                answer[1]++;
            }
        }
        len=b.size();
        s.clear();
        while(len>0){
            if(len%2==1){
                s+="1";
            }
            else{
                s+="0";
            }
            len/=2;
        }
        answer[0]++;
    }
    
    return answer;
}

