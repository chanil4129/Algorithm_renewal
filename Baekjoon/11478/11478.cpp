#include <iostream>
#include <set>
using namespace std;

set<string> u;

int main(void) {
	string S;
	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		string str = ""; //���ڿ�
		for (int j = i; j < S.size(); j++) {
			str += S[j]; //���� ����
			cout << str << "\n";
			u.insert(str); //set�� ���Ҹ� ������ unique�� ���� ���Ե�
		}
	}
	cout << u.size();
}

//https://www.acmicpc.net/problem/11478