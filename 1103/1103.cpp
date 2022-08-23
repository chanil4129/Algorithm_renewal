#include <iostream>
#include <cstring>
using namespace std;

int N, M; //row,column
int MAP[55][55]; //H는 0으로 표현
int mr[] = { -1,1,0,0 };
int mc[] = { 0,0,-1,1 };
int d[55][55]; //DP table
bool visit[55][55]; //방문했는지 확인

int f(int i, int j) {
	//MAP을 넘어가거나 H라면 0 리턴
	if (i < 0 || j < 0 || i >= N || j >= M || MAP[i][j] == 0) return 0;
	//무한반복일 경우 -1 출력후 프로그램 종료
	if (visit[i][j]) {
		cout << "-1";
		exit(0);
	}
	//중복 조건
	int& ret = d[i][j];
	if (ret) return ret;

	visit[i][j] = true; //방문 기록
	for (int k = 0; k < 4; k++) //다음 조건
		ret = max(ret, f(i + MAP[i][j] * mr[k], j + MAP[i][j] * mc[k]) + 1);
	visit[i][j] = false; //아니라면 취소(백트래킹)
	return ret=d[i][j];
}

int main(void) {
	int i, j;
	char c;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cin >> c;
			if (c == 'H') MAP[i][j] == 0;
			else MAP[i][j] = c - '0';
		}
	}
	cout << f(0, 0);
	/*cout << "\n";
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			cout << d[i][j];
		}
		cout << "\n";
	}*/
}

//https://www.acmicpc.net/problem/1103