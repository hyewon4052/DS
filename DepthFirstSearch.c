#include <stdio.h>
#define SIZE 8

typedef enum {false, true} bool;

int stack[SIZE];
int top = -1;
void push(int index) {
	stack[++top] = index;
}

int pop(void) {
	if (top == -1) return -1;
	return stack[top--];
}

void DepthFirstSearch(char V[],bool G[][SIZE]) {	// 2차원 배열을 받을 때 행크기는 생략해도 열 크기는 반드시 주어야 한다.
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = {false};
	printf("출발 정점 : "); scanf_s("%c", &startVertex, 1);
	for (i = 0; i < SIZE; i++) if (V[i] == startVertex) break;
	printf("깊이 우선 탐색 : %c", startVertex);
	searchOK[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == 0) {		// 1 대신 true , 0 대신 false 사용 가능
				printf("-> %c", V[j]);
				searchOK[j] = true;
				push(i);	 // 스택에다 넣어놔야 이전으로 되돌아 갈 수 있음
				i = j;
				break;
			}
		}
		if (j == SIZE) i = pop();
	} while	(i >= 0);
}

int main(void) {
	char V[] = { 'A','B','C','D','E','F','G','H' };
	bool G[SIZE][SIZE] = {{0,1,1,0,0,0,0,0},
						  {1,0,0,1,1,0,0,0},
						  {1,0,0,0,0,1,1,0},
						  {0,1,0,0,0,0,0,1},
						  {0,1,0,0,0,0,0,1},
						  {0,0,1,0,0,0,0,1},
						  {0,0,1,0,0,0,0,1},
						  {0,0,0,1,1,1,1,0}};
	DepthFirstSearch(V, G);
	return 0;
}
