#include <iostream>
#include <vector>
using namespace std;

int stairs[301];//����� cost
int D[301];//����� ���� ����ġ. ans[n]�� ��

void dp(int n) {
	//�迭 �ʱⰪ ����
	D[1] = stairs[1];
	D[2] = stairs[1] + stairs[2];
	D[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
	//an=an-3+bn+bn-3�� an=an-2+bn���� �� ū���� ��
	for (int i = 4; i <= n; i++) 
		D[i] = max(D[i - 3] + stairs[i] + stairs[i - 1], D[i - 2] + stairs[i]);
}

int main(void) {
	int n;//��� ��
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];
	dp(n);
	cout << D[n];
}

//https://www.acmicpc.net/problem/2579