#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
vector <pair<int, int>> p;
double ans;
bool visit[22];

void f(int cnt,int depth) {
	if (depth >= N) return; //leaf�� ���� ����
	if (cnt >= N / 2) { //N/2���� +�ϸ� �Ǵϱ�(������ N/2�� -���ֱ�)
		double x = 0, y = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i]) { //ǥ�õ� N/2���� ���� P�� +���ֱ�
				x += p[i].first;
				y += p[i].second;
			}
			else { //ǥ�þȵ� N/2���� ���� P�� -���ֱ�
				x -= p[i].first;
				y -= p[i].second;
			}
		}
		ans = min(ans, sqrt(x * x + y * y));
		return;
	}
	//-���� ���� P
	f(cnt, depth + 1);
	visit[depth] = true;
	//+���� ���� P
	f(cnt + 1, depth + 1);
	visit[depth] = false;
}

int main(void) {
	int i, j; //for�� ���
	int a, b; //�ӽ� �Է�
	cout << fixed;
	cout.precision(12); //�Ҽ��� 12�ڸ����� ���
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> N;
		p.clear(); //���� �ʱ�ȭ (�Ź� �׽�Ʈ ���̽����� �ʱ�ȭ �۾�)
		ans = numeric_limits<double>::max(); //ans�� �ִ��� ���� (�Ź� �׽�Ʈ ���̽����� �ʱ�ȭ �۾�)
		memset(visit, 0, sizeof(visit)); //�湮�� ���� �ʱ�ȭ (�Ź� �׽�Ʈ ���̽����� �ʱ�ȭ �۾�)
		for (j = 0; j < N; j++) {
			cin >> a >> b ;
			p.push_back({ a, b });
		}
		f(0,0);
		cout << ans << "\n";
	}
}

//https://www.acmicpc.net/problem/1007