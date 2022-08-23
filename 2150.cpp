#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int V, E;		//(���� ����),(����/��Ģ ����)
int id,d[10001];		//(������ȣ),(�θ� ��ȣ)
bool finished[10001];		//(����� üũ��)
vector<int> node[10001];		//������� ����
vector<vector<int>> SCC;		//SCC - ���� ���� ���(Strongly Connected Component). ����Ŭ �ѹ����� �׿� ���� ������ ��� ����
stack<int> s;		//����

int dfs(int x) {
	d[x] = ++id;		//�θ� ��ȣ
	s.push(x);		//��� push
	int parent = d[x];		//�θ� ��ȣ(�񱳸� ����)
	for (int i = 0; i < node[x].size(); i++) {		//���������� ���Ǹ�
		int y = node[x][i];
		if (d[y] == 0) parent = min(parent, dfs(y));		//dfs�� Ž���ϸ� ����Ŭ �߻��� �� parent�� �ּڰ�
		else if (finished[y] == 0) parent = min(parent, d[y]);		//üũ �ȵȰ� �� ����Ŭ �߻��� parent(�ּڰ�)�� �ֱ�
	}
	if (parent == d[x]) {		//�θ� ��ȣ�� ó�� �ڱ� �ڽŰ� ���� �����ٸ� ���ÿ� �ִ� ����Ŭ ��ȣ�� ����
		vector<int> scc;		//����Ŭ �ϳ�
		while (1) {
			int t = s.top();		//top ���� t�� ����
			s.pop();		//pop
			scc.push_back(t);		//top ���� �ֱ�
			finished[t] = true;		//����Ŭ �ϳ� üũ�����Ƿ� true�� �����
			if (t == x) break;		//���� ��尡 ���´ٸ� break
		}
		SCC.push_back(scc);		//����Ŭ �ϳ��� SCC�� ����
	}
	return parent;
}

int main(void) {
	int A, B;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> A >> B;
		node[A].push_back(B);		//���� ��� ���� ����
	}
	for (int i = 1; i <= V; i++) if (d[i] == 0) dfs(i);		//üũ ���� ���� dfs
	for (int i = 0; i < SCC.size(); i++) sort(SCC[i].begin(), SCC[i].end());		//����Ŭ�� ���� ��������
	sort(SCC.begin(), SCC.end());		//����Ŭ���� ù��° ��ȣ�� �������� ��������
	cout << SCC.size() << "\n";		//����Ŭ�� ����
	for (int i = 0; i < SCC.size(); i++) {		//����Ŭ��
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << " ";		//�� ����Ŭ�� ���� ���
		cout << "-1\n";
	}
	return 0;
}

//https://www.acmicpc.net/problem/2150