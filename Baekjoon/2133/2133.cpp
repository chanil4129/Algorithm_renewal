#include <iostream>
using namespace std;

int n;

//int arr[2][31];
//
//int f(int n) {    //��ȭ�� : f(n) = 3*f(n-2) + ( 2*f(n-4) + 2*f(n-6) + ... +2*f(0) )
//	//�ʱⰪ ����
//	arr[0][2] = 3;
//	arr[1][4] = 1;
//	arr[0][4] = 11;
//	if (n % 2) return 0;    //Ȧ���� 0 ����
//	for (int i = 5; i <= n; i++) {		//¦���� ��ȭ�Ĵ��
//		if (n % 2 == 0) {
//			arr[1][i] = arr[0][i - 4] + arr[1][i - 2];
//			arr[0][i] = 3 * arr[0][i - 2] + 2 * arr[1][i];
//		}
//	}
//	return arr[0][n];   //�迭�� ����
//}

int arr[31] = { 1,0,3 };

int f(int n) {    //��ȭ�� : f(n) = 3*f(n-2) + ( 2*f(n-4) + 2*f(n-6) + ... +2*f(0) )
	if (n % 2) return 0;    //Ȧ���� 0 ����
	if (arr[n] != 0) return arr[n];   //¦���� �� 0�� �ƴ� ���̸� �� �迭�� ����
	int result = 3 * f(n - 2);    //��ȭ�� ���� ��, �տ� 3*f(n-2) �κ�
	for (int i = 3; i <= n; i++) if (i % 2 == 0) result += 2 * f(n - i);    //��ȭ�� ���� �� ������ �޺κ�
	return arr[n] = result;   //�迭�� ����
}

int main(void) {
	int n;
	cin >> n;   //�Է�
	cout << f(n);   //���
}

//https://www.acmicpc.net/problem/2133