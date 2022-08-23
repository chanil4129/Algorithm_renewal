#include <iostream>
using namespace std;

#define MAX 2600003

int k; //���� ����
int g; //���� ����
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
			if (d[i - 1][j]) d[i][j] = true; //�� �ȿø���
			if (d[i - 1][abs(j - g)]) d[i][j] = true; //���ʿ� �ø���
			if (d[i - 1][j + g]) d[i][j] = true; //�����ʿ� �ø���
		}
	}
	for (i = 1; i < S; i++) if (!d[k][i]) ans++;
	cout << ans;
}

//https://www.acmicpc.net/problem/17610