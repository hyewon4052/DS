#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right) {
	int* b = (int*)malloc((right - left + 1) * sizeof(int));
	int i = left, j = mid + 1,k=0;

	while (i <= mid && j <= right) {
		if (a[i] < a[j]) b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	if (i > mid) while (j <= right) b[k++] = a[j++];
	else while (i <= mid) b[k++] = a[i++];
	k = 0;
	for (i = left; i <= right; i++) a[i] = b[k++];
	free(b);
}
void division(int a[], int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;
		division(a,left, mid);
		division(a, mid + 1, right);
		merge(a, left, mid, right);
	}
}
int main(void) {
	int a[] = { 5,33,27,12,4,25,10,56,35,18,7 };
	int n = sizeof(a) / sizeof(int);

	division(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	printf("\n");
	return 0;
}