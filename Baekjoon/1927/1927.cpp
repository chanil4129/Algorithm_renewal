#include <iostream>
#include <queue>
using namespace std;

int N;
int x;
priority_queue<int> q; //�켱���� ť

int main(void) {
	//����� �ð�����(���ϸ� �ð��ʰ�)
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0 && !q.empty()) { //0�̰� ������� ������ ���
			cout << -q.top() << "\n";
			q.pop();
		}
		else if (x == 0) cout << 0 << "\n"; //0�ε� ��������� 0 ���
		else q.push(-x); //0 �̿��� ���ڴ� �켱���� ť�� �ֱ�
	}
}

//https://www.acmicpc.net/problem/1927