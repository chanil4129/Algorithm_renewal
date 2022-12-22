#include <string>
#include <vector>

using namespace std;

int bit_count(int n){
    int count=0;
    while(n){
        if(n%2){
            count++;
        }
        n/=2;
    }
    return count;
}

int solution(int n) {
    int answer=0;
    int n_count=0;
    n_count=bit_count(n);
    while(answer==0){
        n++;
        if(n_count==bit_count(n)){
            answer=n;
            break;
        }
    }
    return answer;
}