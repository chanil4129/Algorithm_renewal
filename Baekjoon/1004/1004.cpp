#include <iostream>
using namespace std;

int main(void) {
	int T;//Testcase
	int x1, y1, x2, y2;//������, ������ ��ǥ
	int n;
	int cx, cy, r;//n���� ��
	int count;//ī����

	cin >> T;
	for (int i = 0; i < T; i++) {
		count = 0;//0���� �ʱ�ȭ
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> cx >> cy >> r;
			//������ Ȥ�� ������ �ϳ��� �ۿ� �ϳ��� �ȿ� ������ ī����
			if ((r * r > (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) && r * r < (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)) ||
				(r * r < (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) && r * r >(x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy)))
				count++;
		}
		cout << count << "\n";

	}
}

//https://www.acmicpc.net/problem/1004