#include <iostream>
using namespace std;

int check[51][51];    //���� ���� �� ��ǥ
int M, N;   //(���� ����),(���� ����)

void backtrack(int x, int y) {
    //üũ �����Ƿ� 2�� �ٲٱ�
    if (check[y][x] == 1) check[y][x] = 2;
    //�����¿� ��Ʈ��ŷ
    if (x > 0 && check[y][x - 1] == 1) backtrack(x - 1, y);   //����
    if (x < M - 1 && check[y][x + 1] == 1) backtrack(x + 1, y);   //������
    if (y > 0 && check[y - 1][x] == 1) backtrack(x, y - 1);   //����
    if (y < N - 1 && check[y + 1][x] == 1) backtrack(x, y + 1);   //�Ʒ���
}

int main(void) {
    int T;    //Test case
    int K, X, Y;    //X, Y ��ǥ �Է�
    int count;    //������ ��

    cin >> T;
    for (int t = 0; t < T; t++) {
        count = 0;    //Test ���� ������ �� �ʱ�ȭ
        cin >> M >> N >> K;   //M, N, K �Է�
        //�迭 �ʱ�ȭ
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) check[n][m] = 0;
        //X,Y �Է�
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            check[Y][X] = 1;
        }
        //backtracking
        for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) if (check[n][m] == 1) {   //��Ʈ��ŷ �� ������ �����̼�++
            count++;
            backtrack(m, n);
        }
        //���
        cout << count << "\n";
    }
    return 0;
}

//https://www.acmicpc.net/problem/1012