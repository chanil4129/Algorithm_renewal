#include <iostream>
#include <vector>
using namespace std;

//1��Ǯ��

//int sdk[10][10] = {};		//������ ��
//bool row[10][10] = {}, column[10][10] = {}, square[10][10] = {};		//Ȯ�ο����� (��), (��), (3x3�簢��). ù��° index�� ������� ��, ��, 3x3�簢��, �ι�° index���� 1~9���� ������ �� Ȯ��
//
//void backtrack(int cnt) {		//81������ ��� �湮�ϴ� Ʈ��, x,y ��ǥ�� �����ϸ� ��.
//	int x = cnt / 9;		//x��ǥ
//	int y = cnt % 9;		//y��ǥ
//	if (cnt == 81) {		//������ �� ���
//		for (int i = 0; i < 9; i++) {
//			for (int j = 0; j < 9; j++) cout << sdk[i][j] << " ";
//			cout << endl;
//		}
//		exit(0);		//�������� ���� ��� ����ϱ� ������ �ѹ� ����ϰ� �ٷ� ������ ���� ������ �ʿ���
//	}
//	else if (sdk[x][y] == 0) for (int i = 1; i <= 9; i++) {		//������ �ǿ� 0�� ���� 1~9���� ��带 �ʿ����
//		if (!row[x][i] && !column[y][i] && !square[(x / 3) * 3 + (y / 3)][i]) {		//�ش� ��,��,3x3�簢�� ������ ��� false�϶���
//			sdk[x][y] = i;		//sdk�� �� �ֱ�
//			row[x][i] = true; column[y][i] = true; square[(x / 3) * 3 + (y / 3)][i] = true;		//�ش� ��,��,3x3 ������ ��� true�� �����
//			backtrack(cnt + 1);		//��Ʈ��ŷ
//			sdk[x][y] = 0;		//�ʱ�ȭ
//			row[x][i] = false; column[y][i] = false; square[(x / 3) * 3 + (y / 3)][i] = false;		//�ʱ�ȭ
//		}
//	}
//	else backtrack(cnt + 1);		//������ �ǿ� 0�� �ƴ϶�� �׳� �Ѿ
//}
//
//int main(void) {
//	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {		//�������� �Է�
//		cin >> sdk[i][j];
//		if (sdk[i][j] != 0) {		//�Է��� �������� ���� 0�� �ƴ϶�� �ش� ��,��,3x3�簢������ true�� �ٲ۴�
//			row[i][sdk[i][j]] = true;
//			column[j][sdk[i][j]] = true;
//			square[(i / 3) * 3 + (j / 3)][sdk[i][j]] = true;
//		}
//	}
//	backtrack(0);		//��Ʈ��ŷ
//	return 0;
//}

//2�� Ǯ��

int sdk[9][9];
vector<pair<int, int>> v;

//�ش� val���� �� �� �ִٸ� true �� �� ���ٸ� false
bool isVal(int r, int c, int val) {
    //column
    for (int i = 0; i < 9; i++) {
        if (i == c) continue;
        if (sdk[r][i] == val) return false;
    }
    //row
    for (int i = 0; i < 9; i++) {
        if (i == r) continue;
        if (sdk[i][c] == val) return false;
    }
    //3x3 �׸�ĭ
    for (int i = r / 3 * 3; i < r / 3 * 3 + 3; i++) {
        for (int j = c / 3 * 3; j < c / 3 * 3 + 3; j++) {
            if (i == r && j == c) continue;
            if (sdk[i][j] == val) return false;
        }
    }
    return true;
}

bool f(int n) {
    if (n >= v.size()) return true;

    for (int i = 1; i <= 9; i++) {
        if (isVal(v[n].first, v[n].second, i)) {
            sdk[v[n].first][v[n].second] = i; //�� �ֱ�
            if(f(n + 1)) return true; //������ ã��
            sdk[v[n].first][v[n].second] = 0; //�ƴ϶�� ����
        }
    }

    return false;
}

int main(void) {
	int i, j;
    for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) {
        cin >> sdk[i][j];
        if (sdk[i][j] == 0) v.push_back({ i,j });
    }
	f(0);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cout << sdk[i][j]<< " ";
        }
        cout << "\n";
    }

}

//https://www.acmicpc.net/problem/2580