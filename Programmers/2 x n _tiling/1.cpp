#include <string>
#include <vector>
#define BUF 60006
using namespace std;

int d[BUF];

int solution(int n) {
    d[1]=1;
    d[2]=2;
    for(int i=3;i<BUF;i++){
        d[i]=(d[i-1]+d[i-2])%1000000007;
    }
    return d[n];
}