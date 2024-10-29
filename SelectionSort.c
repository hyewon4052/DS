void SelectionSort(int a[], int n) {
	
	int i = 1, j, min, index;

	
	for (j = i + 1; j < n; j++) {
		min = a[i]; index = i;
		if (min > a[j]) {
			min = a[j];
			index = j;
		}
	}

	a[index] = a[i];
	a[i] = min;
}

int main(void) {
	int a[] = { 11,26,3,1,9,17,7,25,20 };
	int n = sizeof(a) / sizeof(int);
	SelectionSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%5d", a[i]);
	}
	return 0;
}