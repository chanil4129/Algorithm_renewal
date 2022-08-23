#include <iostream>
using namespace std;

int N, M;
int a[1111][1111]; //입력받는 배열
int d[1111][1111]; //DP table 생성
int ans; //출력(정답)

int main(void) {
	//cin, cout 빠르게 해주기(안하면 시간초과 일어남)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int x1, y1, x2, y2;
	cin >> N >> M;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
		cin >> a[i][j];
		d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j]; //DP table 채우기
	}
	for (i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2; //좌표 입력
		ans = d[x2][y2] - d[x2][y1-1] - d[x1-1][y2] + d[x1-1][y1-1]; //채워진 DP table 이용해서 정답 구하기
		cout << ans << "\n";
	}
}

//https://www.acmicpc.net/problem/11660