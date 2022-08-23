#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int dasom; //�ټ��� ������ �ִ� ��ǥ��
priority_queue<int> q; //�켱���� ť
int ans; //����� ����

int main(void) {
	int v,i;
	cin >> N;
	cin >> dasom;
	for (i = 1; i < N; i++) {
		cin >> v;
		q.push(v);
	}
	while (!q.empty()) { //�켱����ť�� ������� ���� ��쿡�� �ݺ�
		if (dasom > q.top()) break; //�ټ��� ��ǥ���� ���� ���� ��ǥ���� ���� �ٸ� �ĺ��ں��� �� ���ٸ� ����
		int current = q.top(); //pop�� �� ����
		//pop�ϰ�, �ٷ� �װź��� 1���� ���� �켱���� ť�� ����(max�� ����)
		q.pop();
		q.push(current - 1);
		//�ټ��� ��ǥ���� ans 1�� ����
		dasom++;
		ans++;
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/1417