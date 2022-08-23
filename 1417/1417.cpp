#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int dasom; //다솜이 가지고 있는 투표수
priority_queue<int> q; //우선순위 큐
int ans; //출력할 정답

int main(void) {
	int v,i;
	cin >> N;
	cin >> dasom;
	for (i = 1; i < N; i++) {
		cin >> v;
		q.push(v);
	}
	while (!q.empty()) { //우선순위큐가 비어있지 않을 경우에만 반복
		if (dasom > q.top()) break; //다솜의 투표수가 가장 많은 투표수를 가진 다른 후보자보다 더 많다면 종료
		int current = q.top(); //pop할 값 저장
		//pop하고, 바로 그거보다 1작은 값을 우선순위 큐에 저장(max힙 유지)
		q.pop();
		q.push(current - 1);
		//다솜의 투표수와 ans 1씩 증가
		dasom++;
		ans++;
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/1417