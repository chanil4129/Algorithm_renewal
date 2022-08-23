#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int c;//card number
vector<int>::iterator low;//lower_bound index
vector<int> v;

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c;
		low = lower_bound(v.begin(), v.end(), c); //lower_bound ��ġ ã��
		if (low-v.begin() == v.size()) //������ index�̸� �״�� ����
			v.push_back(c);
		else //�ٸ� index�� ��ȯ�ϱ�
			v[low-v.begin()] = c;
	}
	cout << v.size();
}

//https://www.acmicpc.net/problem/11568