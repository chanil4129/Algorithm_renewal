#include <iostream>
using namespace std;

//��� 1

//int m, a[33], n, b; //m:���� ����, a:���� ���Ե�, n:Ȯ���� ���� ����, b:Ȯ���� ���� ���Ե�
//bool d[33][15001];
//
//void f(int depth,int weight) {
//	//��������
//	if (depth > m) return;
//	//�ߺ�����
//	if (d[depth][weight]) return;
//	//DP
//	d[depth][weight] = true;
//	//���
//	f(depth + 1, weight + a[depth+1]);
//	f(depth + 1, abs(weight - a[depth+1]));
//	f(depth + 1, weight);
//}
//
//int main(void) {
//	int i, j;
//	cin >> m; //���� ���� �Է�
//	for (i = 1; i <= m; i++) cin >> a[i]; //���� ���Ե� �Է�
//	f(0,0);
//	cin >> n; //Ȯ���� ���� ���� �Է�
//	for (i = 1; i <= n; i++) {
//		cin >> b; //Ȯ���� ���� ���Ե� �Է�
//		if (b > 15000) cout << "N "; //30*500 �ִ� �����̹Ƿ� 15000�� ������ �ǹ̰� ����
//		else if(d[m][b]) cout << "Y "; //DP table���� �ش� ���԰� true�̸� Y
//		else cout << "N "; //�� �ܿ��� N
//	}
//}


//���2

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
		if (b > 15000) cout << "N "; //30*500 �ִ� �����̹Ƿ� 15000�� ������ �ǹ̰� ����
		else if (d[m][b]) cout << "Y "; //DP table���� �ش� ���԰� true�̸� Y
		else cout << "N "; //�� �ܿ��� N
	}
	
}

//https://www.acmicpc.net/problem/2629