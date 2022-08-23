#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 111111

int C, N;
int a, b; //a:홍보할 때 드는 비용. b:그 비용으로 얻을 수 있는 고객의 수
vector<int> v; ////DP table. index는 비용. D[index]는 비용당 가능한 최대 인원

int main(void) {
	cin >> C >> N;
	int i, j;
	v.assign(MAX, 0);
	for (i = 1; i <= N; i++) {
		cin >> a >> b;
		for (j = a; j < MAX; j++) {
			v[j] = max(v[j], v[j - a] + b);
		}
	}
	cout << lower_bound(v.begin(), v.end(), C)-v.begin();
}

//https://www.acmicpc.net/problem/1106