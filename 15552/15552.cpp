#include <iostream>
using namespace std;

int main(void) {
	int T, A, B;
	ios::sync_with_stdio(false);		//C++�� C ǥ�� ��Ʈ�� ����ȭ ����
	cin.tie(NULL);		//����� ���� �����ֱ�
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B;
		cout << A + B << "\n";		//\n�� �ܼ� ����. endl�� ��� ���۸� ���� ���ұ��� ��.
	}
	return 0;
}

//https://www.acmicpc.net/problem/15552