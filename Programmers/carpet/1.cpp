#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int a=1;a<brown+yellow;a++){
        int b=(brown+4)/2-a;
        if(a*b==brown+yellow){
            return vector<int>{b,a};
        }
    }
}