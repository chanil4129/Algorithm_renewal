#include <iostream>
using namespace std;

#define DSIZE 31

int T;
int N,M;
int d[DSIZE][DSIZE];

int main(void){
    cin>>T;
    //Dynamic programming => Combinamtion table 채우기
    d[0][0]=1;
    for(int i=1;i<DSIZE;i++){
        d[i][0]=1;
        d[i][i]=1;
    }
    for(int i=2;i<DSIZE;i++)
        for(int j=1;j<DSIZE-1;j++)
            d[i][j]=d[i-1][j-1]+d[i-1][j];
            
    //인덱스 입력 및 탐색
    for(int i=0;i<T;i++){
        cin>>N>>M;
        cout<<d[M][N]<<"\n";
    }
}

//https://www.acmicpc.net/problem/1010