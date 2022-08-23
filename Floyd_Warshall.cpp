#include <iostream>
using namespace std;

const int INF = 1e9;		//INF �ϰ��� ������ ������ �ȵ� ���
const int number = 5;		//���� ����

int a[5][5] = {		//�������� �������
	{0,1,INF,1,5},
	{9,0,3,2,INF},
	{INF,INF,0,4,INF},
	{INF,INF,2,0,3},
	{3,INF,INF,INF,0}
};

void floyd() {		//floyd �˰���
	int d[number][number];		//���ο� �������
	for (int i = 0; i < number; i++) for (int j = 0; j < number; j++) d[i][j] = a[i][j];		//���� d�� �Ű� ���
	//k�� ���İ��� ����, i�� ���� ����, j�� ���� ����
	for (int k = 0; k < number; k++) for (int i = 0; i < number; i++) for (int j = 0; j < number; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
	for (int i = 0; i < number; i++) {		//����ϱ�
		for (int j = 0; j < number; j++) cout << d[i][j] << " ";
		cout << "\n";
	}
}

int main(void) {
	floyd();		//�÷��̵� �˰���
	return 0;
}