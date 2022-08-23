#include <iostream>
#include <algorithm>
using namespace std;

int R, C;
char a[23][23];
bool isPos[26];
int ans;

void f(int i,int j,int depth) {
	if (i > 1 && isPos[a[i][j] - 'A']) {//╩С
		isPos[a[i][j] - 'A'] = false;
		f(i - 1, j, depth + 1);
		isPos[a[i][j] - 'A'] = true;
	}
	if (i < R && isPos[a[i][j] - 'A']) {//го
		isPos[a[i][j] - 'A'] = false;
		f(i + 1, j, depth + 1);
		isPos[a[i][j] - 'A'] = true;
	}
	if (j > 1 && isPos[a[i][j] - 'A']) {//аб
		isPos[a[i][j] - 'A'] = false;
		f(i, j - 1, depth + 1);
		isPos[a[i][j] - 'A'] = true;
	}
	if (j < C && isPos[a[i][j] - 'A']) {//©Л
		isPos[a[i][j] - 'A'] = false;
		f(i, j + 1, depth + 1);
		isPos[a[i][j] - 'A'] = true;
	}
	ans = max(ans, depth);
	return;
}

int main(void) {
	int i, j;
	cin >> R >> C;
	for (i = 1; i <= R; i++) for (j = 1; j <= C; j++) cin>>a[i][j];

	fill(isPos, isPos + 26, true);
	f(1,1,0);
	cout << ans;
}

//https://www.acmicpc.net/problem/1987