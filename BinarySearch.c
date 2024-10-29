#include <stdio.h>

int cnt = 0;

int binarySearch(int a[], int n, int key) {
	int left = 0, mid, right = n - 1;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt++;
		if (key == a[mid]) return mid;
		if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
*
int main(void) {
	int a[] = { 3,7,10,12,14,18,21,33,35,48 };
	int n = sizeof(a) / sizeof(int);
	int index, key;
	printf("찾을 값 : ");
	scanf("%d", &key);
	index = binarySearch(a, n, key);
	if (index >= 0) printf("%d를 %d위치에서 %d회 비교하여 찾음! \n", key, cnt, index);
	else printf("%d은(는) 없는 데이터임! \n", key);
	return 0;
}