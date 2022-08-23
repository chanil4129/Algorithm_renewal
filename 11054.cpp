#include <iostream>
using namespace std;

int N;
int a[1111];
int lis[1111];
int lds[1111];
int ans;

void LIS() {
	lis[0] = 1;
	for (int i = 1; i < N; i++) {
		int t = 0;
		for (int j = i-1; j >= 0; j--) if (a[i] > a[j]) t = max(t, lis[j]);
		lis[i] = t + 1;
	}
}

void LDS() {
	lds[N - 1] = 1;
	for (int i = N - 2; i >= 0; i--) {
		int t = 0;
		for (int j = i + 1; j < N; j++) if (a[i] > a[j]) t = max(t, lds[j]);
		lds[i] = t + 1;
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	LIS();
	LDS();
	for(int i=0;i<N;i++) ans = max(ans, lis[i] + lds[i] - 1);
	cout << ans;
}

//https://www.acmicpc.net/problem/11054