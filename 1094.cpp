#include <iostream>
using namespace std;

int X;
int ans;

int main(void) {
	int i;
	cin >> X;
	for (i = 0; i < 7; i++) {
		//��Ʈ����ŷ
		if (X & 1) ans++;
		X = X >> 1;
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/1094