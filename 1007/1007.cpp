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
	if (depth >= N) return; //leaf로 가면 종료
	if (cnt >= N / 2) { //N/2개만 +하면 되니깐(나머지 N/2는 -해주기)
		double x = 0, y = 0;
		for (int i = 0; i < N; i++) {
			if (visit[i]) { //표시된 N/2개의 집합 P만 +해주기
				x += p[i].first;
				y += p[i].second;
			}
			else { //표시안된 N/2개의 집합 P는 -해주기
				x -= p[i].first;
				y -= p[i].second;
			}
		}
		ans = min(ans, sqrt(x * x + y * y));
		return;
	}
	//-해줄 집합 P
	f(cnt, depth + 1);
	visit[depth] = true;
	//+해줄 집합 P
	f(cnt + 1, depth + 1);
	visit[depth] = false;
}

int main(void) {
	int i, j; //for문 사용
	int a, b; //임시 입력
	cout << fixed;
	cout.precision(12); //소수점 12자리까지 출력
	cin >> T;
	for (i = 0; i < T; i++) {
		cin >> N;
		p.clear(); //벡터 초기화 (매번 테스트 케이스마다 초기화 작업)
		ans = numeric_limits<double>::max(); //ans에 최댓값을 저장 (매번 테스트 케이스마다 초기화 작업)
		memset(visit, 0, sizeof(visit)); //방문한 벡터 초기화 (매번 테스트 케이스마다 초기화 작업)
		for (j = 0; j < N; j++) {
			cin >> a >> b ;
			p.push_back({ a, b });
		}
		f(0,0);
		cout << ans << "\n";
	}
}

//https://www.acmicpc.net/problem/1007