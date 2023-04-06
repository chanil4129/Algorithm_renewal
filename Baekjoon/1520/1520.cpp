#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T[501][501]; //table ���� ���
int D[501][501]; //D[1][1]�� ��. ����� ����� ���� ��� ����
int M, N; //����, ����

int dp(int m,int n) {
	//����
	if (m == M && n == N) return 1;
	if (m < 1 || n < 1 || m > M || n > N) return 0;
	//�ߺ�
	int &ret = D[m][n];
	if (ret != -1) return ret;
	//Ž��
	int sum = 0;
	if (n > 1 && T[m][n - 1] < T[m][n]) //��
		sum += dp(m, n - 1);
	if (n < N && T[m][n + 1] < T[m][n]) //�Ʒ�
		sum += dp(m, n + 1);
	if (m > 1 && T[m - 1][n] < T[m][n]) //����
		sum += dp(m - 1, n);
	if (m < M && T[m + 1][n] < T[m][n]) //������
		sum += dp(m + 1, n);

	return ret=sum;
}

int main(void) {
	cin >> M >> N;
	//�ʱⰪ ����
	memset(D, -1, sizeof(D));
	D[M][N] = 1;
	for (int m = 1; m <= M; m++) 
		for (int n = 1; n <= N; n++) 
			cin >> T[m][n];
	dp(1,1);
	/*for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			if (D[m][n]==-1) {
				cout << "0 ";
				continue;
			}
			cout << D[m][n]<<" ";
		}
		cout << '\n';
	}*/
	cout << D[1][1];
}

//https://www.acmicpc.net/problem/1520
