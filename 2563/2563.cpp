#include <iostream>
using namespace std;

int N;
int cd[111][111]; //컴퓨터의 픽셀과 비슷

int main() {
	int x,y;
	int ans;
	cin>>N;
	ans=0;
	for(int j=0;j<N;j++){
		cin>>x>>y;
        //픽셀 칠하기
		for(int a=x;a<x+10;a++){
			for(int b=y;b<y+10;b++){
				if(cd[a][b]==1) //픽셀이 채워지지 않을 경우 채우고, 답++
					continue;
				cd[a][b]=1;
				ans++; 
			}
		}
	}
	cout<<ans<<"\n";
	
    return 0;
}

//https://www.acmicpc.net/problem/2563