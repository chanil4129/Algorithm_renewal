#include <iostream>
using namespace std;

int N, M;
bool promising[10] = {};

void backtracking(int level, int index) {
	if (level == M) {		//���°��� Ʈ������ M���� ������ �����ϸ�
		for (int i = 1; i <= N; i++) {		//promising �迭 ���� true�ΰ͵� ���
			if (promising[i] == true) cout << i << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = index + 1; i <= N; i++) {		//���� ������ ������ ū�͸� Ȯ��
			if (promising[i] == false) {		//promising �迭 ���� false�̸� �̱�
				promising[i] = true;		//�̾Ҵٴ� �ǹ�
				backtracking(level + 1, i);		//��Ʈ��ŷ
				promising[i] = false;		//�ʱ�ȭ(�߿�)
			}
		}
	}
}

int main(void) {
	cin >> N >> M;		//�Է�
	backtracking(0,0);		//��Ʈ��ŷ
	return 0;
}

//https://www.acmicpc.net/problem/15650