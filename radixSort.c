#include <stdio.h>
#include <stdlib.h>

void radixSort(int a[], int n) {
    int digit_cnt[10] = { 0, };
    int* b = (int*)malloc(sizeof(int) * n); // 동적할당하여 배열처럼 사용
    int digit = 1, max = a[0], i;

    for (i = 1; i < n; i++)if (max < a[i]) max = a[i];
    while (digit <= max) {
        for (i = 0; i < n; i++)digit_cnt[a[i] / digit % 10]++;
        for (i = 1; i < 10; i++)digit_cnt[i] += digit_cnt[i - 1];
        for (i = n - 1; i >= 0; i--)
            b[--digit_cnt[a[i] / digit % 10]] = a[i];
        for (i = 0; i < n; i++) a[i] = b[i];
        for (i = 0; i < 10; i++)digit_cnt[i] = 0;
        for (i = 0; i < n; i++) printf("%6d", b[i]); printf("\n");
        digit *= 10;
    }
    free(b);
}

int main(void) {
    int a[] = { 10, 50, 512, 3, 1283, 303, 7215, 717, 318, 148, 29, 99 };
    int n = sizeof(a) / sizeof(int);

    radixSort(a, n);

    return 0;
}