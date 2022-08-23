#include <iostream>
using namespace std;

int N, M;		//�Է��� ����
int check[10];		//����� �迭

void backtrack(int level) {
	if (level == M) {		//���̰� M�̸� �迭���� ���
		for (int i = 0; i < M; i++) cout << check[i] << " ";
		cout << "\n";
	}
	//���̰� M���� ������ ������
	else for (int i = 1; i <= N; i++) {		//�ڽĳ��� 1���� N����
			check[level] = i;		//�̱�(�迭���� ���õ� �ڽĳ��)
			backtrack(level + 1);		//��Ʈ��ŷ
	}
}

int main(void) {
	cin >> N >> M;		//�Է�
	backtrack(0);		//��Ʈ��ŷ
	return 0;
}

//https://www.acmicpc.net/problem/15651