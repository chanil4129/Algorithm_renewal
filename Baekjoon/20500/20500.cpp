#include <iostream>
using namespace std;

int N;
int d[1517][3];

int main(void) {
	cin >> N;
	d[2][0] = 1;
	d[2][1] = 1;
	for (int i = 3; i <= 1515; i++) {
		d[i][0] = (d[i - 1][2] + d[i - 1][0]) % 1000000007;
		d[i][1] = (d[i - 1][2] + d[i - 1][1]) % 1000000007;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 1000000007;
	}
	cout << d[N][0];
}

//https://www.acmicpc.net/problem/20500