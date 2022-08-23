#include <iostream>
using namespace std;

int N;
int R, G, B;
int CR[1111], CG[1111], CB[1111];
int d[1111][3]; //0�� R, 1�� G, 2�� B
int ans = 1e9;

int f(int n,int m) {
	int i;
	for (i = 1; i <= N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + CR[i]; //������ G, B�� ���� �����ϹǷ� G, B �ּڰ� ����
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + CG[i]; //������ R, B�� ���� �����ϹǷ� R, B �ּڰ� ����
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + CB[i]; //������ R, G�� ���� �����ϹǷ� R, G �ּڰ� ����
	}
	return min(d[N][n], d[N][m]);
}

int main(void) {
	cin >> N;
	int i, j;
	cin >> R >> G >> B;
	for (i = 2; i <= N; i++) 
		cin >> CR[i] >> CG[i] >> CB[i];
	CR[1] = R;
	CG[1] = 1001;
	CB[1] = 1001;
	ans=f(1,2);
	CR[1] = 1001;
	CG[1] = G;
	CB[1] = 1001;
	ans=min(ans,f(0, 2));
	CR[1] = 1001;
	CG[1] = 1001;
	CB[1] = B;
	ans=min(ans,f(0, 1));
	cout << ans;
}

//https://www.acmicpc.net/problem/17404