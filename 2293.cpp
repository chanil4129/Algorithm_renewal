#include <iostream>
using namespace std;

int n, k;
int c;
int d[10001];

int main(void) {
	cin >> n >> k;
	int i, j;
	d[0] = 1;
	for (i = 0; i < n; i++) {
		cin >> c;
		for (j = c; j <= k; j++) {
			d[j] = d[j] + d[j - c];
		}
	}
	cout << d[k];
}

//https://www.acmicpc.net/problem/2293