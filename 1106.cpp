#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 111111

int C, N;
int a, b; //a:ȫ���� �� ��� ���. b:�� ������� ���� �� �ִ� ���� ��
vector<int> v; ////DP table. index�� ���. D[index]�� ���� ������ �ִ� �ο�

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