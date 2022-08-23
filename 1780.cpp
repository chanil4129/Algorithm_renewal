#include <iostream>
using namespace std;

int N;
int MAP[2200][2200];
int ans[3];

void f(int x, int y, int n) {
	if (n < 1) return;
	int chk = 0;
	for (int i = x; i < x + n; i++) for (int j = y; j < y + n; j++) if (MAP[x][y] != MAP[i][j]) chk = 1; //chk�� 1�θ���� �ϳ��� �ٸ��� ���� �ɰ��ٴ� ǥ��
	if (chk) for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) f(x + (i * n / 3), y + (j * n / 3), n / 3); //���� 9����ϱ�
	else ans[MAP[x][y] + 1]++; //���ɰ� ���� ans�� �� �ֱ�
}

int main(void) {
	int i, j;
	cin >> N;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) cin >> MAP[i][j];
	f(0, 0, N);
	for (i = 0; i < 3; i++) cout << ans[i] << "\n";
}

//https://www.acmicpc.net/problem/1780