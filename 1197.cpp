#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;		//(���� ����),(���� ����)
int node_info[10001];		//�����鰣�� ���� ����(�Ϻθ� �̿�)

class Edge {		//���� ����(������ ����� �� ����, ���, ���� ���� ��)
public:
	int node[2], cost;		//(������ ����� �� ����), (���)
	Edge(int a, int b, int cost) {		//�ʱ�ȭ
		this->node[0] = a;
		this->node[1] = b;
		this->cost = cost;
	}
	bool operator <(Edge& edge) {		//����� �������� ����
		return this->cost < edge.cost;
	}
};

int find(int a) {		//�����鳢���� ���� ���� ã��(����⿡ �ִ� ����)
	if (node_info[a] == a) return a;
	return node_info[a] = find(node_info[a]);
}

void merge(int a, int b) {		//�����鳢�� �����ϱ�
	a = find(a);
	b = find(b);
	if (a < b) node_info[b] = a;		//�������� �ִ´�.
	else node_info[a] = b;
}

int main(void) {
	int A, B, C, sum = 0;		//(����1),(����2),(���),(����� sum��)
	vector<Edge> v;		//���� ������ ���� ����
	cin >> V >> E;		//�Է�
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;		//�Է�
		v.push_back(Edge(A, B, C));		//�ʱ�ȭ
	}
	sort(v.begin(), v.end());		//���������� ����
	for (int i = 0; i < V; i++) node_info[i] = i;		//��� ���� �ʱ�ȭ(���� �ƹ��͵� ���ٸ� �ڱ� �ڽ� ����)
	for (int i = 0; i < v.size(); i++) {
		int a = find(v[i].node[0] - 1);		//a�� ����� ���� ã��
		int b = find(v[i].node[1] - 1);		//b�� ����� ���� ã��
		if (a == b) continue;		//���ٸ� ���� �Ǿ� �ִٴ� ���̹Ƿ� pass
		merge(v[i].node[0] - 1, v[i].node[1] - 1);		//���� �Ǿ� ���� �����Ƿ� ��ġ��
		sum += v[i].cost;		//��� �����ֱ�
	}
	cout << sum;		//��� ���
	return 0;
}

//https://www.acmicpc.net/problem/1197