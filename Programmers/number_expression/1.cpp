#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i=1;i*(i+1)/2<=n;i++){
        int r=n-i*(i+1)/2;
        for(int a=0;i*a<=n;a++){
            if(i*a==r){
                answer++;
                break;
            }
        }
    }
    return answer;
}