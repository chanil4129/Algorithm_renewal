#include <iostream>
using namespace std;

//int N, K;
//string s[55];
//bool a[26];
//int ans;
//
//void f(int n,int depth) {
//	//종료 조건
//	if (n > N) return;
//	int count = 0;
//	for (int i = 0; i < 26; i++) {
//		if (a[i]) count++;
//	}
//	//cout << s[n] << "\n";
//	//cout << "count222 : " << count << "\n";
//	if (count > K) return;
//	//단어 개수 확인
//	for (int i = 4; i < s[n].size()-4; i++) {
//		a[s[n][i]-'a'] = true;
//	}
//	//cout << depth << "\n";
//	count = 0;
//	for (int i = 0; i < 26; i++) {
//		if (a[i]) count++;
//	}
//	//cout << "count : " << count << "\n";
//	if (count <= K) ans = max(ans, depth + 1);
//	//BFS
//	for (int i = n + 1; i < N; i++) {
//		f(i, depth + 1);
//	}
//	for (int j = 4; j < s[n].size() - 4; j++) {
//		a[s[n][j] - 'a'] = false;
//	}
//	a['c' - 'a'] = true;
//	a['a' - 'a'] = true;
//	a['i' - 'a'] = true;
//	a['n' - 'a'] = true;
//	a['t' - 'a'] = true;
//}
//
//int main(void) {
//	int i;
//	cin >> N >> K;
//	a['a' - 'a'] = 1;
//	a['c' - 'a'] = 1;
//	a['i' - 'a'] = 1;
//	a['n' - 'a'] = 1;
//	a['t' - 'a'] = 1;
//	for (i = 0; i < N; i++) {
//		cin >> s[i];
//	}
//	f(0,0);
//	cout << ans;
//}

int N, K;
string s;
int a[55];
int ans;

int bitpop(int v) { //2bit에서 1 개수 세주기
	int cnt = 0;
	while (v) {
		cnt += (v & 1);
		v >>= 1;
	}
	return cnt;
}

int main(void) {
	int x;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; s[j]; j++) a[i] |= (1 << (s[j] - 'a')); //각 단어마다 들어간 글자 2bit로 표시
	}
	x = (1 << ('a'-'a')) | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')); //a,c,i,n,t는 무조건 포함시켜야 하므로
	for (int i = x; i < (1 << 26); i++) { 
		if (bitpop(i |= x) != K) continue; //a,c,i,n,t 포함하며 K개 글자가 맞춰져야만 단어가 포함되는지 체크(안하면 시간초과)
		int cnt = 0;
		for (int j = 0; j < N; j++) cnt += ((i & a[j]) == a[j]); //단어가 포함되는지 확인
		ans = max(ans, cnt); //최댓값이 답
	}
	cout << ans;
}

//https://www.acmicpc.net/problem/1062