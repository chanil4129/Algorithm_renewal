#include <iostream>
#include <math.h>
using namespace std;

bool arr[1001];
int n, k, cnt = 0;

void primeNumberSieve() {
	for (int i = 2; i <= n; i++) for (int j = i; j <= n; j += i) {		//���� ������ �����佺�׳׽��� ü
		if (arr[j] == true) continue;		//�̹� �����ٸ� �Ѿ��
		arr[j] = true;		//P �����(true���� �������)
		cnt++;		//ī����
		if (cnt == k) cout << j;		//k��°�̸� ���
	}
	
}

int main(void) {
	cin >> n >> k;		//�Է�
	primeNumberSieve();		//�����佺�׳׽��� ü ����
	return 0;
}

//https://www.acmicpc.net/problem/2960