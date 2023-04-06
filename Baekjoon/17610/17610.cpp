#include <iostream>
using namespace std;

#define MAX 2600003

int k; //추의 개수
int g; //추의 무게
int S;
bool d[15][MAX];
int ans;

int main(void) {
	cin >> k;
	int i, j;
	d[0][0] = true;
	for (i = 1; i <= k; i++) {
		cin >> g;
		S += g;
		for (j = 0; j < MAX - g; j++) {
			if (d[i - 1][j]) d[i][j] = true; //추 안올리기
			if (d[i - 1][abs(j - g)]) d[i][j] = true; //왼쪽에 올리기
			if (d[i - 1][j + g]) d[i][j] = true; //오른쪽에 올리기
		}
	}
	for (i = 1; i < S; i++) if (!d[k][i]) ans++;
	cout << ans;
}

//https://www.acmicpc.net/problem/17610