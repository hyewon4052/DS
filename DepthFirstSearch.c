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

void DepthFirstSearch(char V[],bool G[][SIZE]) {	// 2���� �迭�� ���� �� ��ũ��� �����ص� �� ũ��� �ݵ�� �־�� �Ѵ�.
	int i, j;
	char startVertex;
	bool searchOK[SIZE] = {false};
	printf("��� ���� : "); scanf_s("%c", &startVertex, 1);
	for (i = 0; i < SIZE; i++) if (V[i] == startVertex) break;
	printf("���� �켱 Ž�� : %c", startVertex);
	searchOK[i] = true;

	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && searchOK[j] == 0) {		// 1 ��� true , 0 ��� false ��� ����
				printf("-> %c", V[j]);
				searchOK[j] = true;
				push(i);	 // ���ÿ��� �־���� �������� �ǵ��� �� �� ����
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