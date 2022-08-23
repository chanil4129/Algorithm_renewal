#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;		//INF �� ����(���� �ȵ��� ���)
int T, n, d, c, cnt;		//(Test case),(��ǻ�� ����),(������ ����),(��ŷ���� ��ǻ�� ��ȣ.�� ���� ��ȣ)
vector<pair<int, int>> computer[10001];		//������ ������ ��Ÿ���� ���� ����. first�� �ð�(���), seconde�� ���� ���ϴ� ����
int total_time[10001];		//�� �ҿ� �ð�

void infection() {		//���ͽ�Ʈ�� �˰������� �ذ�
	total_time[c] = 0;		//���� ��ǻ��
	priority_queue<pair<int, int>> pq;		//�켱���� ť�� ����� ������ �ذ��ϱ� ����
	pq.emplace(0, c);		//���� ����
	while (!pq.empty()) {		//ť�� ������� �ʴٸ�
		int current = pq.top().second;		//���� ��ǻ��
		int cost = -pq.top().first;		//���� �ð�(max ���̹Ƿ� ����ȭ�� �̿�)
		pq.pop();		//pop
		if (total_time[current] < cost) continue;		//�ִܽð��� �ƴ� ��� pass 
		for (int i = 0; i < computer[current].size(); i++) {		////���Ϳ� ��� pair�� ���� ��ŭ��
			int next = computer[current][i].second;		//���� ��ǻ��
			int next_cost = cost + computer[current][i].first;		//���� ��ǻ���� �ð�
			if (total_time[next] > next_cost) {		//���� �ð��� ���� ���� �ִ� �ð����� �� ���ٸ�
				total_time[next] = next_cost;		//���� ����
				pq.emplace(-next_cost, next);		//��ǻ�� �߰�(�켱���� ť�� �ִ� �� ������ ���� ������ �̸� �̿��� ����ȭ �ϱ�)
			}
		}
	}
}

int main(void) {
	int a, b, s, max;		//(����a),(����b),(�ð�),(�ִ�)
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> d >> c;
		for (int j = 1; j <= n; j++) while (!computer[j].empty()) computer[j].pop_back();		//�Ź� case���� ���� �ʱ�ȭ
		for (int j = 0; j < d; j++) {
			cin >> a >> b >> s;
			computer[b].push_back(make_pair(s, a));		//������� ���� �Է�(���� ����)
		}
		for (int j = 1; j <= n; j++) total_time[j] = INF;		//�������� �ʰ� �ִٸ� INF
		cnt = 0; max = 0;		//�Ź� case���� �ʱ�ȭ
		infection();		//���ͽ�Ʈ��
		for (int j = 1; j <= n; j++) if (total_time[j] != INF) {		//������ ��ǻ�� ���� ���� ���������� ������ �ð� ���ϱ�
			if (max < total_time[j]) max = total_time[j];
			cnt++;
		}
		cout << cnt << " " << max << "\n";		//���
	}
	return 0;
}

//https://www.acmicpc.net/problem/10282