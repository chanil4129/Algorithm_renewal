#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void){
    string s="   hello  WoRld aaaa   ";
    string answer = "";
    string token;
    int pos;
        
    while(true){
        pos = s.find(" ");
        token = s.substr(0, pos);
        s=s.substr(pos+1);
        cout<< token.length()<<"\n";
        answer+=token;
        answer+=" ";


        if(pos==s.npos)
            break;
    }
    
    if(!answer.empty())
        answer.pop_back();
    
    cout<<answer<<"\n";
    cout<<answer.back()<<"\n";
    if(answer.back()==' ')
     cout<<"kasjdfkda"<<"\n";
}