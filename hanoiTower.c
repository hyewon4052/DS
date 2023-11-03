#include <stdio.h>

void HanoiTower(int n, char a, char b, char c) {	// a = 출발지 변수, b = 경유지 변수, c = 도착지 변수
	if (n == 1) printf("원판 %d, %c -> %c \n", n, a, c);	// n = 원판 번호
	else {
		HanoiTower(n - 1, a, c, b);
		printf("원판 %d , %c -> %c \n", n, a, c);
		HanoiTower(n - 1, b, a, c);
	}
}

int main(void) {
	int n = 4;
	HanoiTower(n, 'A', 'B', 'C');
	return 0;
}

