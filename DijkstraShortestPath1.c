#include <stdio.h>
#include <limits.h>

#define SIZE 8
#define M INT_MAX

typedef enum { false, true } bool;

int minVertex(int D[], int chk[]) {
	int i, minValue = M, minIndex = 0;

	for (i = 0; i < SIZE; i++) {
		if (chk[i] == 0 && minValue > D[i]) {
			minValue = D[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void Dijkstra(int G[][SIZE], int D[], int P[], int i) {
	// 준비
	int j, cnt = 0;
	bool chk[SIZE] = { false };

	// 발표 여기서 부터!!!!!
	
	//1단계
	for (j = 0; j < SIZE; j++) {
		if (G[i][j] > 0 && G[i][j] < M) {
			D[j] = G[i][j];
			P[j] = i;
		}
	}
	chk[i] = true;
	cnt++;
	//2단계~마지막
	while (cnt < SIZE) {
		i = minVertex(D, chk);
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] > 0 && G[i][j] < M) {
				if (D[j] > D[i] + G[i][j]) {
					D[j] = D[i] + G[i][j];
					P[j] = i;
				}
			}
		}
		chk[i] = true;
		cnt++;
	}
}	// 발표 여기까지!!!!!


int main(void) {
	int G[SIZE][SIZE] = { {0, 12, 15, 18, M, M, M, M}, //A의 인접 정보
					  {12, 0, M, M, 33, 26, M, M}, //B의 인접 정보
					  {15, M, 0, 7, M, 10, M, M}, //C의 인접 정보
					  {18, M, 7, 0, M, M, 11, M}, //D의 인접 정보
					  {M, 33, M, M, 0, 17, M, 15}, //E의 인접 정보
					  {M, 26, 10, M, 17, 0, M, 28}, //F의 인접 정보
					  {M, M, M, 11, M, M, 0, 20}, //G의 인접 정보
					  {M, M, M, M, 15, 28, 20, 0}}; //H의 인접 정보
	char V[SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	char aV, bV;
	int D[SIZE] = { M, M, M, M, M, M, M, M };
	int P[SIZE] = { 0, }, i;

	printf("출발 정점: ");
	scanf_s("%c", &aV, 1);
	getchar();
	printf("도착 정점: ");
	scanf_s("%c", &bV, 1);
	getchar();

	//도착 정점 인덱스 구하기
	for (i = 0; i < SIZE; i++) if (bV == V[i]) break;
	//도착 정점에 대한 거리 및 경로 초기화
	D[i] = 0; P[i] = i;

	//최단 경로 및 거리 구하기

	Dijkstra(G, D, P, i);

	//출발점에서 도착점까지 최단 거리 및 경로 출력하기
	for (i = 0; i < SIZE; i++) if (aV == V[i]) break;
	printf("\n%c에서 %c까지 최단거리: %d\n", aV, bV, D[i]);
	printf("최단경로: %c", aV);
		while (V[i] != bV) {
			i = P[i];
			printf(" -> %c", V[i]);
		}
	printf("\n");

	return 0;
}