#include <iostream>
using namespace std;

int N, M;
int a[1111][1111]; //�Է¹޴� �迭
int d[1111][1111]; //DP table ����
int ans; //���(����)

int main(void) {
	//cin, cout ������ ���ֱ�(���ϸ� �ð��ʰ� �Ͼ)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	int x1, y1, x2, y2;
	cin >> N >> M;
	for (i = 1; i <= N; i++) for (j = 1; j <= N; j++) {
		cin >> a[i][j];
		d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + a[i][j]; //DP table ä���
	}
	for (i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2; //��ǥ �Է�
		ans = d[x2][y2] - d[x2][y1-1] - d[x1-1][y2] + d[x1-1][y1-1]; //ä���� DP table �̿��ؼ� ���� ���ϱ�
		cout << ans << "\n";
	}
}

//https://www.acmicpc.net/problem/11660