#include <iostream>
#include <cstring>
using namespace std;

int N;
char MAP[111][111];
bool visit[111][111];
int ans;

void f(int i, int j) {
	if (i > 0 && !visit[i - 1][j] && MAP[i][j] == MAP[i - 1][j]) {//╩С
		visit[i - 1][j] = true;
		f(i - 1, j);
	}
	if (i < N - 1 && !visit[i + 1][j] && MAP[i][j] == MAP[i + 1][j]) {//го
		visit[i + 1][j] = true;
		f(i + 1, j);
	}
	if (j > 0 && !visit[i][j - 1] && MAP[i][j] == MAP[i][j - 1]) {//аб
		visit[i][j - 1] = true;
		f(i, j - 1);
	}
	if (j < N - 1 && !visit[i][j + 1] && MAP[i][j] == MAP[i][j + 1]) {//©Л
		visit[i][j + 1] = true;
		f(i, j + 1);
	}
}

int main(void) {
	cin >> N;
	int i, j;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) cin >> MAP[i][j];
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
		if (!visit[i][j]) {
			ans++;
			f(i, j);
		}
	}
	cout << ans<<" ";
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) if (MAP[i][j] == 'G') MAP[i][j] = 'R';
	ans = 0;
	memset(visit, 0, sizeof(visit));
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) {
		if (!visit[i][j]) {
			ans++;
			f(i, j);
		}
	}
	cout << ans;
}