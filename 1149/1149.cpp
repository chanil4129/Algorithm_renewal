#include <iostream>
#include <algorithm>
using namespace std;

int N;
int R, G, B;
int d[1111][3]; //0은 R, 1은 G, 2는 B
int ans=1e9;

int main(void) {
	cin >> N;
	int i, j;
	for (i = 1; i <= N; i++) {
		cin >> R >> G >> B;
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R; //이전에 G, B만 선택 가능하므로 G, B 최솟값 선택
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G; //이전에 R, B만 선택 가능하므로 R, B 최솟값 선택
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B; //이전에 R, G만 선택 가능하므로 R, G 최솟값 선택
	}
	ans = min({ d[i - 1][0],d[i - 1][1],d[i - 1][2] });
	cout << ans;
}

//https://www.acmicpc.net/problem/1149