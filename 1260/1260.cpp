#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<int> v[1111];
bool d[1111]; //dfs�� �湮 ǥ��
bool b[1111]; //bfs�� �湮 ǥ��

void dfs(int n) {
	if (d[n]) return; //�湮�� ���̸� �Ѿ��
	cout << n << " ";
	d[n] = true; //�湮 ǥ��
	for (int i = 0; i < v[n].size(); i++) //���
		dfs(v[n][i]);
}

void bfs(int n) {
	queue<int> q; //ť
	q.push(n); //ť �ʱⰪ
	b[n] = true; //V �湮�����ϱ� ǥ���س���
	while (!q.empty()) { //ť�� �ƹ��͵� ���� ������ �ݺ�
		int current = q.front(); //pop�� �� ����
		cout << current << " "; //pop�� �� ���
		q.pop();
		for (int i = 0; i < v[current].size(); i++) {
			if (b[v[current][i]]) continue; //�湮�� ���̸� �Ѿ��
			b[v[current][i]] = true; //�湮���� ���� �� �湮�ϸ鼭 �湮�ߴٴ� ǥ��
			q.push(v[current][i]); //�湮���� ���� �� queue�� �ֱ�
		}
	}
}

int main(void) {
	int i, j;
	int a, b;
	cin >> N >> M >> V;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		//������̹Ƿ� �ΰ� �ֱ�
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (i = 1; i <= N; i++) //������ ���� ����ؾ� �ϹǷ� sorting ���ֱ�
		sort(v[i].begin(), v[i].end());
	dfs(V);
	cout << "\n";
	bfs(V);
}

//https://www.acmicpc.net/problem/1260