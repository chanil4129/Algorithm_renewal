#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100
#define INF 1000000000

int n = 6, result;
int capacity[MAX][MAX], flow[MAX][MAX], d[MAX];
vector<int> v[MAX];

void network_flow(int start, int end) {//dfs��� �����ϸ� ��
	while (1) {
		fill(d, d + MAX, -1);		//d ��� �� -1�� �ʱ�ȭ(��� �ٽ����)
		queue<int> q;		//ť�� dfs
		q.push(start);		
		while (!q.empty()) {
			int x = q.front();		//�����鼭
			q.pop();
			for (int i = 0; i < v[x].size(); i++) {		//���� ���
				int y = v[x][i];
				if (capacity[x][y] - flow[x][y] > 0 && d[y] == -1) {		//�湮 ���Ѱ͵��� �뷮 ���� ��� ����߰�
					q.push(y);
					d[y] = x;
					if (y == end) break;		//�� �����Ѱ��
				}
			}
		}
		if (d[end] == -1) break;		//��ΰ� ���̻� ������ ����
		int f = INF;		//�ʱ�ȭ(min�� ã�� ����)
		for (int i = end; i != start; i = d[i]) f = min(f, capacity[d[i]][i] - flow[d[i]][i]);		//���� �Ǵ�
		for (int i = end; i != start; i = d[i]) {		//���� �ֱ�
			flow[d[i]][i] += f;
			flow[i][d[i]] -= f;
		}
		result += f;		//�� ��� ����
	}
}

int main(void) {
	v[1].push_back(2);
	v[2].push_back(1);
	capacity[1][2] = 12;

	v[1].push_back(4);
	v[4].push_back(1);
	capacity[1][4] = 11;

	v[2].push_back(3);
	v[3].push_back(2);
	capacity[2][3] = 6;

	v[2].push_back(4);
	v[4].push_back(2);
	capacity[2][4] = 3;

	v[2].push_back(5);
	v[5].push_back(2);
	capacity[2][5] = 5;

	v[2].push_back(6);
	v[6].push_back(2);
	capacity[2][6] = 9;

	v[3].push_back(6);
	v[6].push_back(3);
	capacity[3][6] = 8;

	v[4].push_back(5);
	v[5].push_back(4);
	capacity[4][5] = 9;

	v[5].push_back(3);
	v[3].push_back(5);
	capacity[5][3] = 3;

	v[5].push_back(6);
	v[6].push_back(5);
	capacity[5][6] = 4;

	network_flow(1, 6);
	printf("%d", result);
	return 0;
}

