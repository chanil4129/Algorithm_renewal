#include <iostream>
using namespace std;

//방법 1

//int m, a[33], n, b; //m:추의 개수, a:추의 무게들, n:확인할 추의 개수, b:확인할 추의 무게들
//bool d[33][15001];
//
//void f(int depth,int weight) {
//	//종료조건
//	if (depth > m) return;
//	//중복조건
//	if (d[depth][weight]) return;
//	//DP
//	d[depth][weight] = true;
//	//재귀
//	f(depth + 1, weight + a[depth+1]);
//	f(depth + 1, abs(weight - a[depth+1]));
//	f(depth + 1, weight);
//}
//
//int main(void) {
//	int i, j;
//	cin >> m; //추의 개수 입력
//	for (i = 1; i <= m; i++) cin >> a[i]; //추의 무게들 입력
//	f(0,0);
//	cin >> n; //확인할 추의 개수 입력
//	for (i = 1; i <= n; i++) {
//		cin >> b; //확인할 추의 무게들 입력
//		if (b > 15000) cout << "N "; //30*500 최대 무게이므로 15000이 넘으면 의미가 없음
//		else if(d[m][b]) cout << "Y "; //DP table에서 해당 무게가 true이면 Y
//		else cout << "N "; //그 외에는 N
//	}
//}


//방법2

int m, a, n, b;
bool d[33][15002];

int main(void) {
	int i, j;
	cin >> m;
	d[0][0] = true;
	for (i = 1; i <= m; i++) {
		cin >> a;
		for (j = 0; j <= 15000; j++) {
			if (d[i - 1][abs(j - a)]) d[i][j] = true;
			if (d[i - 1][j + a]) d[i][j] = true;
			if (d[i - 1][j]) d[i][j] = true;
		}
	}
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> b;
		if (b > 15000) cout << "N "; //30*500 최대 무게이므로 15000이 넘으면 의미가 없음
		else if (d[m][b]) cout << "Y "; //DP table에서 해당 무게가 true이면 Y
		else cout << "N "; //그 외에는 N
	}
	
}

//https://www.acmicpc.net/problem/2629