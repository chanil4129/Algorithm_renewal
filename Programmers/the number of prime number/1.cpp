#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

//k 진수로 변환
string k_num(int n,int k){
    string num="";
    while(n>0){
        num+='0'+n%k;
        n/=k;
    }
    reverse(num.begin(),num.end());
    return num;
}

bool is_prime(long long n){
    int end=(int) sqrt(n);
    
    if(n<2){
        return false;
    }
    for(long long i=2;i<=end;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string conversion=k_num(n,k);
    vector<long long> v;
    string tok="";
    //소수 리스트
    for(int i=0;i<conversion.size();i++){
        if(conversion[i]=='0'){
            v.push_back(stoll(tok));
            tok="";
        }
        tok+=conversion[i];
    }
    v.push_back(stoll(tok));
    //소수 찾기
    for(int i=0;i<v.size();i++){
        if(is_prime(v[i]))
            answer++;
    }
    return answer;
}