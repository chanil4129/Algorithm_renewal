#include <iostream>
using namespace std;

int N, cnt = 0;		//(�Է�),(���)
int matrix[20] = {};		//row�� index, column�� ���̶� �����ϸ� ��

bool promising(int row) {
	for (int i = 1; i < row; i++) if (!(matrix[row] - matrix[i]) || !(abs(row - i) - abs(matrix[row] - matrix[i]))) return false;		//����, �밢�� Ȯ���ؼ� ��ġ�� �������� ����
	return true;		//�� �ܿ��� ������
}

void backtrack(int row) {
	if (promising(row)) {		//�����Ҷ���
		if (row == N) cnt++;		//��� row�� ��ġ�� ���
		else for (int column = 1; column <= N; column++) {		//�ڽ� ��忡 ��� column ���� �־�鼭
			matrix[row + 1] = column;		//�ڽ� ��忡 column�� �ֱ�
			backtrack(row + 1);		//��Ʈ��ŷ
		}
	}
}

int main(void) {
	cin >> N;		//�Է�
	backtrack(0);		//��Ʈ��ŷ
	cout << cnt;		//���
	return 0;
}

//https://www.acmicpc.net/problem/9663