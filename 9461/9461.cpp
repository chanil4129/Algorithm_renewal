#include <iostream>
using namespace std;

long long P[101]; //int�� �ϸ� overflow �Ͼ

void dp(int n) {
	//�ʱⰪ ����
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;
	//��ȭ�� : P[n] = P[n-1] + P[n-5]
	for (int i = 6; i <= n; i++) 
		P[i] = P[i - 1] + P[i - 5];
}

int main(void) {
	int T;
	int N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		dp(N);
		cout << P[N] << '\n';
	}
}

//https://www.acmicpc.net/problem/9461