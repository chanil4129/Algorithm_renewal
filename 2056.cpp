#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, run_time[10001], state[10001], result[10001];		//(�۾� ����),(���� ���̿� �ɸ��� �ð�),(���� ����),(������ ���� �����Ͽ� �� �ɸ��� �ð�=>���⼭ ���� ū ������� ������ ����)
vector<int> v[10001];		//(���� ��� ��Ÿ����)

void topologySort() {		//���� ����
	queue<int> q;		//ť
	for (int i = 1; i <= N; i++) if (state[i] == 0) {		//ó�� ������ ť�� �ֱ�
		q.push(i);		//���� �߰�
		result[i] = run_time[i];		//����� ����
	}
	for (int i = 1; i <= N; i++) {
		//if (q.empty()) return;		//����Ŭ �߻��� ����(���� �������� ���� ����)
		int temp = q.front();		//pop�ϱ� �� ���� ������ �ֱ�
		q.pop();
		for (int j = 0; j < v[temp].size(); j++) {		//���� ���� Ȯ���ϸ鼭
			int zero = v[temp][j];		
			if (--state[zero] == 0) q.push(zero);		//���������� ���߰�(���� ����), ���� �߰�
			result[zero] = max(result[zero], result[temp] + run_time[zero]);		//����� ����
		}
	}
}

int main(void) {
	int w_num, w, ans=0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> run_time[i] >> w_num;
		for (int j = 0; j < w_num; j++) {
			cin >> w;
			v[w].push_back(i);
			state[i]++;		//���� ���� ���̱�(���� �߰�)
		}
	}
	topologySort();		//���� ����
	for (int i = 1; i <= N; i++) ans = max(ans, result[i]);		//����� �� ���� ū �� ã��=>����
	cout << ans;		//�� ���
}

//https://www.acmicpc.net/problem/2056