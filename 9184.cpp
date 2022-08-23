#include <iostream>
using namespace std;

int abc[21][21][21];		//������ ��

int w(int a, int b, int c) {		//���ǿ� ���� ����
	if (a <= 0 || b <= 0 || c <= 0) return 1;		
	else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	//���� abc[a][b][c]�� �־��ָ鼭 �ߺ���� ���̱�
	else if (abc[a][b][c] != 0) return abc[a][b][c];
	else if (a < b && b < c) return abc[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return abc[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
	int A, B, C;
	while (true) {
		cin >> A >> B >> C;		//�Է�
		if (A == -1 && B == -1 && C == -1) break;		//-1 -1 -1 �Է��ϸ� ����
		printf("w(%d, %d, %d) = %d\n", A, B, C, w(A, B, C));		//���
	}
	return 0;
}

//https://www.acmicpc.net/problem/9184