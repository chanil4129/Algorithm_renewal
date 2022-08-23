#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int V, E, start;		//(���� ����),(���� ����),(���� ����)
vector<pair<int, int>> node[20001];		//����, ����, ��� ������ ���� ����
int d[200001];		//����� �ִ� ��ΰ�

void dijkstra() {
	d[start] = 0;		//�������� 0
	priority_queue<pair<int, int>> pq;		//�켱���� ť�� ���� �� ���� ���
	pq.push(make_pair(0, start));		//�������� ��� (0, start)
	while (!pq.empty()) {		//pair�� ��� ���� ���� ������ �ݺ�
		int current = pq.top().second;		//���� ����
		int distance = -pq.top().first;		//���� ���(�켱���� ť�� �ִ� �� ������ ���� ������ �̸� �̿��� ����ȭ �ϱ�)
		pq.pop();		//ť���� ������
		//if (d[current] < distance) continue;		//�ִܰŸ��� �ƴ� ��� pass (��� ä������� ����x)
		for (int i = 0; i < node[current].size(); i++) {		//���Ϳ� ��� pair�� ���� ��ŭ��
			int next = node[current][i].second;		//���� ����
			int next_distance = distance + node[current][i].first;		//���� ���
			if (d[next] > next_distance) {		//���� ����� ���� ���� �ִ� ��ΰ����� �� ���ٸ�
				d[next] = next_distance;		//���� ����
				pq.push(make_pair(-next_distance, next));		//���� �߰�(�켱���� ť�� �ִ� �� ������ ���� ������ �̸� �̿��� ����ȭ �ϱ�)
			}
		}
	}
}

int main(void) {
	int u, v, w;		//(����1),(����2),(���)
	cin >> V >> E >> start;		//�Է�
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;		//�Է�
		node[u].push_back(make_pair(w, v));		//����� ���� ����, �׸��� first���� ���, second���� ���� ����(������ �ڵ� �Ʒ� ����)
	}
	for (int i = 1; i <= V; i++) d[i] = INF;		//���� ������ ���ٸ� INF�� �ʱ�ȭ
	dijkstra();		//���ͽ�Ʈ��
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << "\n";		//���� INF��� "INF"�� ���
		else cout << d[i] << "\n";		//INF�� �ƴ϶�� ��� �״�� ���
	}
	return 0;
}

//https://www.acmicpc.net/problem/1753