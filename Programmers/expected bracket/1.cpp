#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a--;b--; //0번 부터 부여
    while(a!=b){
        a/=2;
        b/=2;
        answer++;
    }
    
    
    return answer;
}