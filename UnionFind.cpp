#include <iostream>
using namespace std;

int get_parent(int v[], int x) {		//�θ� V�� ���Ѵ�, ���� ���� ��������.
	if (v[x] == x) return x;
	return v[x] = get_parent(v, v[x]);
}

void union_parent(int v[], int x, int y) {		//V �����ϱ�. 
	x = get_parent(v, x);		
	y = get_parent(v, y);
	if (x < y) v[y] = x;		//�� �������� ��������
	else v[x] = y;
}

void find_parent(int v[], int x, int y) {		//����Ǿ� �ִ��� Ȯ��
	x = get_parent(v, x);
	y = get_parent(v, y);
	if (x == y) cout<<"connected";
	else cout<<"not_connected";
}

int main(void) {
	int arr[10];
	for (int i = 0; i < 10; i++) arr[i] = i;
	//1~4���� ����, 5~9���� ����
	union_parent(arr, 1, 2);
	union_parent(arr, 2, 3);
	union_parent(arr, 3, 4);
	union_parent(arr, 5, 6);
	union_parent(arr, 6, 7);
	union_parent(arr, 7, 8);
	union_parent(arr, 8, 9);
	cout << "1�� 9 ������� : ";
	find_parent(arr,1,9);		//1~4���� ����Ǿ� �ְ�, 5~9������ ����Ǿ� ����.
	//���� ��
	union_parent(arr, 4, 5);		//4,5 ����
	cout << "\n1�� 9 ������� : ";
	find_parent(arr, 1, 9);		//4,5�� ����Ǹ� 1~9���� ��� ����ȴ�.
}