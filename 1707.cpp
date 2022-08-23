#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int K;
int V, E;
vector<int> p[22222];
int c[22222];

bool f(int v) {
	for (int i = 1; i <= v; i++) {
		if (c[i] == 0) c[i] = 1;
		for (int j = 0; j < p[i].size(); j++) {
			if (c[p[i][j]] == 0) {
				if (c[i] == 1) c[p[i][j]] = 2;
				if (c[i] == 2) c[p[i][j]] = 1;
				continue;
			}
			if(c[i]==c[p[i][j]]) return false;
		}
	}
	//for (int i = 1; i <= v; i++) cout << c[i] << " ";
	//cout << "\n";
	for (int i = 1; i <= v; i++) {
		for (int j = 0; j < p[i].size(); j++) {
			if (c[i] == c[p[i][j]]) return false;
		}
	}
	return true;
}

int main(void) {
	int a, b;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> V >> E;
		memset(c, 0, sizeof(c));
		for (int j = 0; j < 22222; j++) p[j].clear();
		for (int j = 0; j < E; j++) {
			cin >> a >> b;
			p[a].push_back(b);
			p[b].push_back(a);
		}
		if (f(V)) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
}

//https://www.acmicpc.net/problem/1707