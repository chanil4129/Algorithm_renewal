#include <iostream>
#include <string>
using namespace std;

int main(){
    string k[9]={"c=","c-","dz=","d-","lj","nj","s=","z="};
    string s;
    cin>>s;
    for(int i=0;i<8;i++){
        std::size_t pos = s.find(k[i]);
        while(pos!=std::string::npos){
            s.replace(pos,k[i].length(),"#");
            pos=s.find(k[i],pos);
        }
    }
    cout<<s.length();
}