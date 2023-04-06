#include <iostream>
#include <queue>
using namespace std;

int N;
int x;
priority_queue<int> q; //우선순위 큐

int main(void) {
	//입출력 시간단축(안하면 시간초과)
	ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0 && !q.empty()) { //0이고 비어있지 않으면 출력
			cout << -q.top() << "\n";
			q.pop();
		}
		else if (x == 0) cout << 0 << "\n"; //0인데 비어있으면 0 출력
		else q.push(-x); //0 이외의 숫자는 우선순위 큐에 넣기
	}
}

//https://www.acmicpc.net/problem/1927