#include <stdio.h>

int fibonacciSearch(int a[], int n, int key) {
	int fibo[] = { 0,1,1,2,3,5,8,13,21,34,55 };
	int index = 0, k = 0, pos;
	while (fibo[k] < n)k++;
	while (k > 0) {
		pos = index + fibo[--k];
		printf("pos = %d\n", pos);
		if (pos < n) {
			if (key == a[pos]) return pos;
			if (key > a[pos]) {
				index = pos;
				k--;
			}
		}
	}
	return -1;
}

int main() {
	int a[] = { 3,5,8,11,15,21,30,37,42,56,58,61,64,67,70,73,75,82,94,99,107 };
	int n = sizeof(a) / sizeof(int);
	int index, key;
	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = fibonacciSearch(a, n, key);
	if (index >= 0) printf("%d 위치에서 찾음! \n", index);
	else printf("없는 Data임! \n");
	return 0;
}
