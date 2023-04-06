#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int x[1000001];
vector<int> v;

//binary search(���ĵ� ���¸� ����)
//int bin_search(int target,int low,int high) {
//	//����
//	if (low > high) return -1;
//	//Ž��
//	int mid = (low + high) / 2;
//	if (v[mid] == target) { //ã�� ���� ���´ٸ�
//		cout << mid << " ";
//		return mid;
//	}
//	else if (v[mid] > target) //ã�� ������ ũ�ٸ�
//		return bin_search(target, low, mid - 1);
//	else //ã�� ������ �۴ٸ�
//		return bin_search(target, mid + 1, high);
//}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
		v.push_back(x[i]);
	}
	sort(v.begin(), v.end()); //���� ����
	//���ĵ� ���Ϳ��� �ߺ��� ���� ����(unique�� �ߺ����� �ڷ� ����. �ڷ� ���� �ߺ����� ����)
	v.erase(unique(v.begin(), v.end()), v.end()); 
	for (int i = 0; i < N; i++)
		//bin_search(x[i],0,v.size());
		cout<<lower_bound(v.begin(), v.end(), x[i])-v.begin()<<" "; //lower_bound�� ���� ����Ž��
}

//https://www.acmicpc.net/problem/18870