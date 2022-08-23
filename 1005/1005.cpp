#include <iostream>
#include <queue>
#include <vector>
#include <string.h>		//memset�� ���� ����
using namespace std;

int N, K, D[1001], state[1001], result[1001];		//(�ǹ� ����),(��Ģ ����),(�ǹ� �Ǽ��� �ɸ��� �ð�),(�ǹ� ���� ����),(��� ��)
vector<int> v[1001];		//���� ��� ����

void topologySort() {		//��������
	queue<int> q;		//ť
	for (int i = 1; i <= N; i++) if (state[i] == 0) {		//���� ���� ���� 0�̸�
		q.push(i);		//ť�� �ֱ�
		result[i] = D[i];		//��� �� ����
	}
	for (int i = 1; i <= N; i++) {		//��� ���� Ȯ��
		if (q.empty()) return;		//���� ������� ����Ŭ�� ����Ƿ� ����
		int temp = q.front();		//pop�ϱ��� ���� ����
		q.pop();
		for (int j = 0; j < v[temp].size(); j++) {		//���� ���� Ȯ���ϸ鼭
			int zero = v[temp][j];
			if (--state[zero] == 0) q.push(zero);		//���� ���� ���߸鼭 ���� ����� ���� ������ 0�̸� ť�� �ֱ�
			result[zero] = max(result[zero], result[temp] + D[zero]);		//����� ����
		}
	}
}

int main(void) {
	int T;		//(Test case)
	int X, Y;		//X->Y ��� ����
	int W;		//W�� �ǹ� ���µ� �ɸ��� �ð�
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 0; j <= N; j++) v[j].resize(0);		//���� �ʱ�ȭ
		memset(D, 0, sizeof(D));		//D �ʱ�ȭ
		memset(state, 0, sizeof(state));		//state �ʱ�ȭ
		memset(result, 0, sizeof(result));		//result �ʱ�ȭ
		for (int j = 1; j <= N; j++) cin >> D[j];
		for (int k = 0; k < K; k++) {
			cin >> X >> Y;
			v[X].push_back(Y);
			state[Y]++;		//���� ���� +1
		}
		cin >> W;
		topologySort();		//��������
		cout << result[W] << "\n";		//W �ǹ� ���� �� �ɸ��� �ð� ���
	}
	return 0;
}

//https://www.acmicpc.net/problem/1005