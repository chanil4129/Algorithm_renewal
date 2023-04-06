#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;		//(���� ��),(���� ��)

class Edge {		//������ ����� ���� 2���� ��� ���� ����
public:
	int node[2];		//����� ����
	int cost;		//���
	Edge(int a, int b, int c) {		//�ʱ�ȭ
		this->node[0] = a;
		this->node[1] = b;
		this->cost = c;
	}
	bool operator <(Edge& edge) {		//���� ����
		return this->cost < edge.cost;		//����� ������
	}
};

//Union-Find
int get_parent(int node[], int a) {		//�θ� ���� ���
	if (node[a] == a) return a;
	return node[a] = get_parent(node, node[a]);
}

bool find_node(int node[],int a, int b) {		//���� a,b�� ����Ǿ� �ִ��� Ȯ��
	a = get_parent(node, a);
	b = get_parent(node, b);
	if (a == b) return true;		//����Ǹ� true
	else return false;		//���� �ȵǾ������� false
}

void union_node(int node[], int a, int b) {		//���� a,b �����ϱ�
	a = get_parent(node, a);
	b = get_parent(node, b);
	if (a < b) node[b] = a;		//�� ���� �� �ֱ�	
	else node[a] = b;
}

int main(void) {
	int a, b, c, sum = 0;		//�Է� �޴� a,b,c �׸��� ����� sum. sum�� 0���� �ʱ�ȭ
	int* node;		//node�� ���� ������ ���� �迭 
	cin >> n >> m;		//�Է�
	vector<Edge> v;		//���� vector
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;		//�Է�
		v.push_back(Edge(a, b, c));		//���� ���� �ֱ�
	}
	sort(v.begin(), v.end());		//������ ����� ����
	node = new int[n];		//node ���� �Ҵ�
	for (int i = 0; i < n; i++) node[i] = i;		//�ƹ��͵� ����Ǿ� ���� �ʴٸ� �ڱ��ڽ��� ����Ŵ
	for (int i = 0; i < v.size(); i++) {
		if (!find_node(node, v[i].node[0] - 1, v[i].node[1] - 1)) {		//�ش� edge�� node�� ���� �ȵǾ� �ִٸ�
			union_node(node, v[i].node[0] - 1, v[i].node[1] - 1);		//�� node ����
			sum += v[i].cost;		//��� �����ֱ�
		}
	}
	cout << sum;		//��� ���
	delete[] node;		//node �Ҵ� ����
	return 0;
}

//https://www.acmicpc.net/problem/1922