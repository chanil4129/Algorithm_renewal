#include <iostream>
#include <string.h>		//memset�� ���� ����
using namespace std;

int n, D;		//(���� ����),(����� ��)
int node[100001], state[100001];		//(node ����),(���� ����)
bool result[100001];		//(�� index�� ī���� �ߴ��� ���)

void dfs(int i) {
	result[i] = true;		//ī����
	D++;		//����� ��++, 
	state[node[i]]--;		//��������--
	if (!result[node[i]] && !state[node[i]]) dfs(node[i]);		//�ڽĳ��� ���� Ȯ��(������ Ȯ��(ī����)���� �ʾҴٸ�, ���������� 0�϶� dfs)
}

int main(void) {
	int T;		//(Test case)
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;		
		D = 0;		//Test case ���� ans �ʱ�ȭ
		memset(state, 0, sizeof(state));		//Test case ���� state �ʱ�ȭ
		memset(result, 0, sizeof(result));		//Test case ���� result �ʱ�ȭ
		for (int j = 1; j <= n; j++) {
			cin >> node[j];		//j->node[j]
			state[node[j]]++;		//��������++
		}
		for (int j = 1; j <= n; j++) if (!result[j] && !state[j]) dfs(j);		//��� �������� Ȯ���ϸ鼭 ������ Ȯ��(ī����)���� �ʾҴٸ�, ���������� 0�϶� dfs
		cout << D << "\n";		//��� ���
	}
	return 0;
}

//https://www.acmicpc.net/problem/9466