#include <string>
#include <vector>

using namespace std;

string transform_tolower(string str){
    for(char &c:str){
        c=tolower(c);
    }
    return str;
}

int solution(string str1, string str2) {
    int answer = 0;
    double ans;
    vector<string> v1;
    vector<string> v2;
    str1=transform_tolower(str1);
    str2=transform_tolower(str2);
    for(int i=1;i<str1.size();i++){
        if(str1[i]<'a'||str1[i]>'z'||str1[i-1]<'a'||str1[i-1]>'z')
            continue;
        string s="";
        s+=str1[i-1];
        s+=str1[i];
        v1.push_back(s);
    }
    for(int i=1;i<str2.size();i++){
        if(str2[i]<'a'||str2[i]>'z'||str2[i-1]<'a'||str2[i-1]>'z')
            continue;
        string s="";
        s+=str2[i-1];
        s+=str2[i];
        v2.push_back(s);
    }
    vector<string> vc1(v1);
    vector<string> vc2(v2);
    vector<string> inter;
    for(int i=0;i<vc1.size();i++){
        for(int j=0;j<vc2.size();j++){
            if(vc1[i]==vc2[j]){
                inter.push_back(vc1[i]);
                vc2.erase(vc2.begin()+j);
                break;
            }
        }
    }
    vector<string> uni(vc2);
    vector<string>::iterator it=uni.insert(uni.end(),vc1.begin(),vc1.end());
    if(uni.size()==0)
        return 65536;
    ans=(double)inter.size()/(double)uni.size();
    answer=ans*65536;
    return answer;
}