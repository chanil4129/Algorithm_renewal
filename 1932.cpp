#include <iostream>
#include <algorithm>
using namespace std;

int t[501][501]; //table ������
int d[501][501]; //dynamic �迭
int ans;

void dp(int n) {
	//�ʱⰪ ����
	d[1][1] = t[1][1];
	//��ȭ�� 
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + t[i][j];
	//���� ū �� ã��
	for (int i = 1; i <= n; i++) if (ans < d[n][i]) ans = d[n][i];
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= i; j++) 
			cin >> t[i][j];
	dp(n);
	cout << ans;
}

//https://www.acmicpc.net/problem/1932