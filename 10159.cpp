#include <iostream>
using namespace std;

int d[101][101];		//�������

int main(void) {
	int N, M;		//(���� ����),(���ǵ� ���� ����)
	int a, b;		//(���ſ� ����),(������ ����)
	cin >> N >> M;		//�Է�
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		d[a][b]=1;		//���⼺ �׷����� ���谡 �ִٸ� 1�� �����
	}
	//floyd �˰���
	for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) if (d[i][k] && d[k][j]) d[i][j] = 1;
	for (int i = 1; i <= N; i++) {
		int cnt = -1;		//�ڱ��ڽ��� ī��Ʈ�� �� �����ϱ� ������ -1�� �ʱ�ȭ
		for (int j = 1; j <= N; j++) if (!d[i][j] && !d[j][i]) cnt++;		//���÷� 1->3, 3->1 �� �ϳ��� ���谡 �ִٸ� ī��Ʈx
		cout << cnt << "\n";		//���
	}
	return 0;
}

//https://www.acmicpc.net/problem/10159