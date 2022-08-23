#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
vector<int> v[1111];
bool d[1111]; //dfs의 방문 표시
bool b[1111]; //bfs의 방문 표시

void dfs(int n) {
	if (d[n]) return; //방문한 곳이면 넘어가기
	cout << n << " ";
	d[n] = true; //방문 표시
	for (int i = 0; i < v[n].size(); i++) //재귀
		dfs(v[n][i]);
}

void bfs(int n) {
	queue<int> q; //큐
	q.push(n); //큐 초기값
	b[n] = true; //V 방문했으니깐 표시해놓기
	while (!q.empty()) { //큐에 아무것도 없을 때까지 반복
		int current = q.front(); //pop할 값 저장
		cout << current << " "; //pop할 값 출력
		q.pop();
		for (int i = 0; i < v[current].size(); i++) {
			if (b[v[current][i]]) continue; //방문한 곳이면 넘어가기
			b[v[current][i]] = true; //방문하지 않은 곳 방문하면서 방문했다는 표시
			q.push(v[current][i]); //방문하지 않은 곳 queue에 넣기
		}
	}
}

int main(void) {
	int i, j;
	int a, b;
	cin >> N >> M >> V;
	for (i = 0; i < M; i++) {
		cin >> a >> b;
		//양방향이므로 두개 넣기
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (i = 1; i <= N; i++) //작은거 부터 출력해야 하므로 sorting 해주기
		sort(v[i].begin(), v[i].end());
	dfs(V);
	cout << "\n";
	bfs(V);
}

//https://www.acmicpc.net/problem/1260