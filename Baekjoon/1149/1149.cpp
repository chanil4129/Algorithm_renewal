#include <iostream>
#include <algorithm>
using namespace std;

int N;
int R, G, B;
int d[1111][3]; //0�� R, 1�� G, 2�� B
int ans=1e9;

int main(void) {
	cin >> N;
	int i, j;
	for (i = 1; i <= N; i++) {
		cin >> R >> G >> B;
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R; //������ G, B�� ���� �����ϹǷ� G, B �ּڰ� ����
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G; //������ R, B�� ���� �����ϹǷ� R, B �ּڰ� ����
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B; //������ R, G�� ���� �����ϹǷ� R, G �ּڰ� ����
	}
	ans = min({ d[i - 1][0],d[i - 1][1],d[i - 1][2] });
	cout << ans;
}

//https://www.acmicpc.net/problem/1149