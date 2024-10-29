#include <stdio.h>

int cnt = 0;
int interpolationSearch(int a[], int left, int right, int key) {
    int mid;
    while (left <= right) {
        cnt++;
        if (a[left] == a[right]) mid = left;
        else {
            mid = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
            if (mid < left) mid = left;
            if (mid > right) mid = right;
        }
        if (key == a[mid]) return mid;
        else if (key < a[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main(void) {
    int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
    int n = sizeof(a) / sizeof(int);
    int index, key;

    printf("찾을 값 : ");
    scanf_s("%d", &key);

    index = interpolationSearch(a, 0, n - 1, key);

    if (index >= 0) printf("%d위치에서 %d회 비교하여 찾음!\n", index, cnt);
    else printf("없는 데이터임!\n");

    return 0;
}