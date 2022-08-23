#include <iostream>
#include <cstring>
using namespace std;

int N, M; //row,column
int MAP[55][55]; //H�� 0���� ǥ��
int mr[] = { -1,1,0,0 };
int mc[] = { 0,0,-1,1 };
int d[55][55]; //DP table
bool visit[55][55]; //�湮�ߴ��� Ȯ��

int f(int i, int j) {
	//MAP�� �Ѿ�ų� H��� 0 ����
	if (i < 0 || j < 0 || i >= N || j >= M || MAP[i][j] == 0) return 0;
	//���ѹݺ��� ��� -1 ����� ���α׷� ����
	if (visit[i][j]) {
		cout << "-1";
		exit(0);
	}
	//�ߺ� ����
	int& ret = d[i][j];
	if (ret) return ret;

	visit[i][j] = true; //�湮 ���
	for (int k = 0; k < 4; k++) //���� ����
		ret = max(ret, f(i + MAP[i][j] * mr[k], j + MAP[i][j] * mc[k]) + 1);
	visit[i][j] = false; //�ƴ϶�� ���(��Ʈ��ŷ)
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