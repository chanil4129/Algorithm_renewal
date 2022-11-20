#include <stdio.h>
#include <stdlib.h>

#define INF 999

typedef struct edge {//edege 구조체 s,d는 연결된 두정점. w는 가중치
	int s, d;
	int w;
}EDGE;

struct vertices {
	int p;
	int rank;
}vt[11];//정점 10개 생성(index 0은 제외)

EDGE e[13];//엣지들 m은 13개

void mst_kruskal(int, int);
void make_set(int);
void merge(int, int);
int find_set(int);
void sort(int);
void max_heapify(int, int);
void max_heap(int);

int n = 10;
int W[INF][INF];//1번문제
int Wv8[INF][INF];//2번문제
int W1[INF][INF], W2[INF][INF];//1번,2번 출력할 배열


void print_array(int n, int W[][INF]) {//MST 인접행렬 출력하기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (W[i][j] == INF)
				printf(" INF");
			else
				printf("%4d", W[i][j]);
		}
		printf("\n");
	}
}

void prim(int n, int W[][INF], int F[][INF]) {
	int i, vnear, min, total = 0;
	int* nearest = new int;//공간 할당
	int* distance = new int;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			F[i][j] = INF;


	for (i = 2; i <= n; i++) { // 초기화
		nearest[i] = 1; // vi에서 가장 가까운 정점을 v1으로 초기화
		distance[i] = W[1][i]; // vi과 v1을 잇는 이음선의 가중치로 초기화
	}
	for (int k = 0; k < n - 1; k++) { // n-1개 정점 연결
		min = INF;
		for (i = 2; i <= n; i++) // 각 정점에 대해서
			if (0 <= distance[i] && distance[i] <= min) { // distance[i]를 검사하여
				min = distance[i]; // 가장 가까이 있는 vnear을
				vnear = i; // 찾는다.
			}

		//F에 정보 저장
		F[vnear][nearest[vnear]] = distance[vnear];
		F[nearest[vnear]][vnear] = distance[vnear];
		total += distance[vnear];//가중치 누적

		distance[vnear] = -1; // 찾은 정점을 추가한다.
		for (i = 2; i <= n; i++)
			if (W[i][vnear] < distance[i]) { // F정보에 없는 각 정점에 대해서
				distance[i] = W[i][vnear]; // distance[i]를 갱신한다.
				nearest[i] = vnear;
			}
	}

	printf("가중치 : %d\n", total);
}

int main(void) {
	int array[10][10] = {//그래프 정보 입력  (1번문제)
		{0,32,INF,17,INF,INF,INF,INF,INF,INF},
		{32,0,INF,INF,45,INF,INF,INF,INF,INF},
		{INF,INF,0,18,INF,INF,5,INF,INF,INF},
		{17,INF,18,0,10,INF,INF,3,INF,INF},
		{INF,45,INF,10,0,28,INF,INF,25,INF},
		{INF,INF,INF,INF,28,0,INF,INF,INF,6},
		{INF,INF,5,INF,INF,INF,0,59,INF,INF},
		{INF,INF,INF,3,INF,INF,59,0,4,INF},
		{INF,INF,INF,INF,25,INF,INF,4,0,12},
		{INF,INF,INF,INF,INF,6,INF,INF,12,0},
	};

	int array2[10][10] = {//그래프 정보 입력  (2번문제)
		{INF,4,INF,INF,INF,INF,3,INF,INF,59},
		{4,INF,12,INF,INF,INF,INF,25,INF,INF},
		{INF,12,INF,INF,INF,INF,INF,INF,6,INF},
		{INF,INF,INF,INF,32,INF,17,INF,INF,INF},
		{INF,INF,INF,32,INF,INF,INF,45,INF,INF},
		{INF,INF,INF,INF,INF,INF,18,INF,INF,5},
		{3,INF,INF,17,INF,18,INF,10,INF,INF},
		{INF,25,INF,INF,45,INF,10,INF,28,INF},
		{INF,INF,6,INF,INF,INF,INF,28,INF,INF},
		{59,INF,INF,INF,INF,5,INF,INF,INF,INF},
	};

	//그래프 정보 입력-3번
	e[0].s = 1, e[1].s = 1, e[2].s = 2, e[3].s = 3, e[4].s = 3, e[5].s = 4, e[6].s = 4, e[7].s = 5, e[8].s = 5, e[9].s = 6, e[10].s = 7, e[11].s = 8, e[12].s = 9;
	e[0].d = 2, e[1].d = 4, e[2].d = 5, e[3].d = 4, e[4].d = 7, e[5].d = 5, e[6].d = 8, e[7].d = 6, e[8].d = 9, e[9].d = 10, e[10].d = 8, e[11].d = 9, e[12].d = 10;
	e[0].w = 32, e[1].w = 17, e[2].w = 45, e[3].w = 18, e[4].w = 5, e[5].w = 10, e[6].w = 3, e[7].w = 28, e[8].w = 25, e[9].w = 6, e[10].w = 59, e[11].w = 4, e[12].w = 12;

	for (int i = 1; i <= n; i++)//v1부터 v10까지 복사
		for (int j = 1; j <= n; j++)
			W[i][j] = array[i - 1][j - 1];

	for (int i = 1; i <= n; i++)//v1부터 v10까지 복사
		for (int j = 1; j <= n; j++)
			Wv8[i][j] = array2[i - 1][j - 1];

	printf("<<1번 문제>>\n");
	prim(n, W, W1);
	printf(" v1  v2  v3  v4  v5  v6  v7  v8  v9  v10    (행렬 v는같음)\n");
	print_array(n, W1);

	// printf("\n\n\n<<2번 문제>>\n");
	// prim(n, Wv8, W2);
	// printf(" v8  v9  v10  v1  v2  v3  v4  v5  v6  v7    (행렬 v는같음)\n");
	// print_array(n, W2);
	// printf("1번 문제 결과와 같다.");

	// printf("\n\n\n<<3번 문제>>\n");
	// mst_kruskal(10, 13);

	return 0;
}

//여기서 부턴 크루스칼 알고리즘
void make_set(int v) {//10개의 정점들 초기화
	vt[v].p = v;//체크 하기 위함
	vt[v].rank = 0;//집합 관계를 나타내기 위함
}

int find_set(int v) {//집합 찾기
	if (vt[v].p != v)
		vt[v].p = find_set(vt[v].p);

	return vt[v].p;
}

void merge(int v, int u) {//두 정점 연결
	v = find_set(v);//v의 집합 찾기
	u = find_set(u);//u의 집합 찾기

	if (vt[v].rank > vt[u].rank)//집합의 상위 p한테 감
		vt[u].p = v;
	else {
		vt[v].p = u;
		if (vt[v].rank == vt[u].rank) {
			vt[u].rank = vt[u].rank + 1;//집합의 상위 포식자 개념(?)이라 생각하면 됨. 보고서 디버그쪽 참고.
		}
	}
}

void mst_kruskal(int nv, int ne) {//크루스칼 알고리즘,prameter는 정점과 엣지의 개수
	int i;
	int total = 0;

	printf("                   (순서쌍으로 표기)\n");
	for (i = 1; i <= nv; i++)//초기화
		make_set(i);

	sort(ne);//엣지들 가중치에 따라 정렬하기

	for (i = 0; i < ne; i++) {
		if (find_set(e[i].s) != find_set(e[i].d)) {//두 집합이 다른 집합(서로소)이면
			merge(e[i].s, e[i].d);//서로소인 두 집합 연결(엣지 유효)
			total = total + e[i].w;//가중치 누적하기
			printf("(v%d, v%d)\n", e[i].s, e[i].d);//정점 순서쌍 출력
		}
	}
	printf("가중치 : %d", total);//가중치 출력
}

//heap_sort
void sort(int ne) {//heap 정렬
	EDGE temp;//교환을 위한 임시 엣지

	max_heap(--ne);//heap 구조 완성

	for (int i = ne; i > 0; i--) {
		//루트 노드를 뽑아 마지막 노드와 값을 바꾼다.
		temp = e[i];
		e[i] = e[0];//max값이 i에 고정(i값은 작아지므로 e[1]부터 e[13]까지 본다면 오름차순임)
		e[0] = temp;

		max_heapify(0, i);//축소된 사이즈로 heap재구성
	}
}

void max_heapify(int index, int size) {
	EDGE temp;//교환을 위한 임시 엣지
	int left = index * 2 + 1;//왼쪽 자식
	int right = index * 2 + 2;//오른쪽 자식
	int large = index;//바꿀 위치

	if (left < size && e[left].w > e[large].w)
		large = left;

	if (right < size && e[right].w > e[large].w)
		large = right;

	if (large != index) {
		temp = e[large];
		e[large] = e[index];
		e[index] = temp;

		max_heapify(large, size);//자리 찾을 때까지 재귀
	}
}

void max_heap(int ne) {//힙 구조 완성
	for (int i = ne / 2; i >= 0; i--)//자식있는 것부터 반복
		max_heapify(i, ne);
}
