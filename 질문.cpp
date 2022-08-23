#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int>> node[7]; // ���� �����Դϴ�. 
int d[7]; // �ּ� ����Դϴ�. 

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int> > pq; // �� �����Դϴ�. a[1].push_back(make_pair(2, 2));
	pq.push(make_pair(start, 0));
	// ����� ������� ó���ϹǷ� ť�� ����մϴ�.
	while(!pq.empty()) {
		int current = pq.top().first;
		// ª�� ���� ���� ������ ����ȭ(-)�մϴ�. 
		int distance = -pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ�մϴ�. 
		if(d[current] < distance) continue;
		for(int i = 0; i < node[current].size(); i++) {
			// ���õ� ����� ���� ��� 
			int next = node[current][i].first; 
			// ���õ� ��带 ���� ���� ���ļ� ���� ��� 
			int nextDistance = distance + node[current][i].second;
			// ������ �ּ� ��뺸�� �� �����ϴٸ� ��ü�մϴ�. 
			if(nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main(void) {
	// �⺻������ ������� ���� ��� ����� �����Դϴ�. 
	for(int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	
	node[1].push_back(make_pair(2, 2));
	node[1].push_back(make_pair(3, 5));
	node[1].push_back(make_pair(4, 1));
	
	node[2].push_back(make_pair(1, 2));
	node[2].push_back(make_pair(3, 3));
	node[2].push_back(make_pair(4, 2));
	
	node[3].push_back(make_pair(1, 5));
	node[3].push_back(make_pair(2, 3));
	node[3].push_back(make_pair(4, 3));
	node[3].push_back(make_pair(5, 1));
	node[3].push_back(make_pair(6, 5));
	
	node[4].push_back(make_pair(1, 1));
	node[4].push_back(make_pair(2, 2));
	node[4].push_back(make_pair(3, 3));
	node[4].push_back(make_pair(5, 1));
	
	node[5].push_back(make_pair(3, 1));
	node[5].push_back(make_pair(4, 1));
	node[5].push_back(make_pair(6, 2));
	
	node[6].push_back(make_pair(3, 5));
	node[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	// ����� ����մϴ�. 
	for(int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	}
}