#include <iostream>
using namespace std;

int N, M;		//�Է��� ����
int arr[10];		//����� �迭

void backtrack(int level, int index) {
	if (level == M) {		//���̰� M�̸� �迭���� ���
		for (int i = 0; i < M; i++) cout << arr[i] << " ";
		cout << "\n";
	}
	//���̰� M���� ������ ������
	else for (int i = index; i <= N; i++) {		//�ڽĳ��� �θ��� ������ N����
		arr[level] = i;		//�̱�(�迭���� ���õ� �ڽĳ��)
		backtrack(level + 1, i);		//��Ʈ��ŷ
	}
}

int main(void) {
	cin >> N >> M;		//�Է�
	backtrack(0, 1);		//��Ʈ��ŷ
	return 0;
}

//https://www.acmicpc.net/problem/15652