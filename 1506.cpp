#include <iostream>
using namespace std;

int N;		//���� ����
int visit[101][101];		//���� ����(�������)
int cost[101], visited[101];		//(���� �Ǽ� ���),(�������� �������� Ȯ��->����� üũ�ϱ� �����ε�, �� �������� ���� ���� ����� �����ش�) 

int main(void) {
	int ans = 0;		//����� ��(�ּҺ��)
	string input;		//������� �Է�
	cin >> N;
	for (int i = 0; i < N; i++) cin >> cost[i];
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) visit[i][j] = input[j] - '0';		//�ٿ��� �Է��ϹǷ� ���� ���� �޾������
	}
	//�÷��̵� �˰����� ���� ��� �ľ�
	for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (visit[i][k] && visit[k][j]) visit[i][j] = 1;
	for (int i = 0; i < N; i++) if (!visited[i]) {		//�湮���� ���� �����϶��� ����(�湮 �������� 0)
		int k = cost[i];		//�ּ� ���
		for (int j = 0; j < N; j++) if (visit[i][j] & visit[j][i]) {		//�Դٰ��� �� �� �ִ� ���õ鸸 �ϳ��� �����̹Ƿ� �׶��� ����
			if (k > cost[j]) k = cost[j];		//�� ���ܿ��� �ּҺ������ ����
			visited[j] = 1;		//�湮�� �����̹Ƿ� 1�� �ٲ��ֱ�
		}
		ans += k;		//�� ���ܿ��� �ּҺ���� �����ֱ�
	}
	cout << ans;		//�� ���
	return 0;
}

//https://www.acmicpc.net/problem/1506