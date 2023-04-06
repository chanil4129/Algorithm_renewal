#include <iostream>
using namespace std;

int N, M;   //�Է�
int check[10];    //����� �迭(index���� ����� �� �ֱ�)
bool promising[10] = {};    //�������� Ȯ��(0�� ����), 0���� �ʱ�ȭ

void backtrack(int level) {   //���°��� Ʈ���� level
    if (level == M) {   //level�� M�̸� ���
        for (int i = 0; i < M; i++) cout << check[i] << " ";
        cout << "\n";
    }
    //1���� N���� ������ ���� Ȯ���ϴµ� backtracking�� ���
    else for (int i = 1; i <= N; i++) if (promising[i] == 0) {    //�����ϴٸ�
        promising[i] = true;    //������ �ߺ����� �ʰ�
        check[level] = i;   //��¹迭�� �� �ֱ�              
        backtrack(level + 1);   //backtracking
        promising[i] = false;   //�ڷ� ���ƿ��� ����      
    }
}

int main(void) {
    cin >> N >> M;    //�Է�
    backtrack(0);   //backtraking
}