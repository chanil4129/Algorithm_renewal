#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <string> v;

int sum(string a) {		//���� �� sum ���ϱ�
	int n = a.length(), sum = 0;
	for (int i = 0; i < n; i++) if (a[i] - '0' >= 0 && a[i] - '0' <= 9) sum += a[i] - '0';		//�����ڵ� ���ֱ�
	return sum;
}

bool compare(string a, string b) {
	//���� ª���� ����
	if (a.length() < b.length()) return 1;
	else if (a.length() > b.length()) return 0;
	else {
		//������ ������ ����
		int asum = sum(a);
		int bsum = sum(b);
		if (asum < bsum) return 1;
		else if (asum > bsum) return 0;
		//������ ����
		else return a < b;
	}
}

int main(void) {
	cin >> n;		//���� �Է�
	string input;		//��Ÿ��ȣ �Է�
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);		//���Ϳ� �ֱ�
	}
	sort(v.begin(), v.end(), compare);		//����
	for (int i = 0; i < n; i++) cout << v[i] << endl;		//���
	return 0;
}

//https://www.acmicpc.net/problem/1431
//https://chanshare.tistory.com/64