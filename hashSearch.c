#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 21
#define SIZE 30

int main(void) {
	char fruit[LEN];
	char fList[SIZE][LEN];
	char overflowArea[10][LEN]; //적재율 75%
	char next;
	int fInt = 0, cnt = 0, i = 0, index = 0;

	//해시 테이블(버킷) 초기화
	for (; i < SIZE; i++) strcpy_s(fList[i], LEN, "");

	//독립 오버플로우 구역 초기화
	for (i = 0; i < 10; i++) strcpy_s(overflowArea[i], LEN, "");

	//제산함수(제수의 조건은 지키지 않음)를 사용하여 해시테이블에 과일명 저장
	do {
		printf("영문 과일명(20글자 이내): ");
		gets_s(fruit, LEN);

		i = 0;
		while (*(fruit + i)) fInt += (int)*(fruit + i++);

		if (strcmp(fList[fInt % SIZE], "")) {
			printf("%d회 충돌 발생!!\n", ++cnt);
			strcpy_s(overflowArea[index++], LEN, fruit);
		}
		else strcpy_s(fList[fInt % SIZE], LEN, fruit);

		fInt = 0;
		printf("계속 입력(y/n): ");
		scanf_s("%c", &next, 1);
		getchar();

	} while (next == 'y' || next == 'Y');

	printf("\n저장 공간\n");
	for (i = 0; i < SIZE; i++) {
		printf("인덱스 %d: %s\n", i, fList[i]);
	}

	printf("\n\n독립 오버플로우 구역\n");
	for (i = 0; i < 10; i++) {
		printf("인덱스 %d: %s\n", i, overflowArea[i]);
	}

	return 0;
}