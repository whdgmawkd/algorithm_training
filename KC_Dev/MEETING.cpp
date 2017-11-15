#include <stdio.h>
int t, n;
int g[10001];
int m[10001];
int abs(int n) {
	return n > 0 ? n : -n;
}
void quickSort(int *arr, int left, int right) {
	int l = left;
	int r = right;
	int tmp;
	int pivot = (arr[left] + arr[right]) / 2;
	while (l <= r) {
		while (arr[l] < pivot) {
			l++;
		}
		while (arr[r] > pivot) {
			r--;
		}
		if (l <= r) {
			tmp = arr[r];
			arr[r] = arr[l];
			arr[l] = tmp;
			r--;
			l++;
		}
	}
	if (left < r) {
		quickSort(arr, left, r);
	}
	if (l < right) {
		quickSort(arr, l, right);
	}
}
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		int sum = 0;
		scanf_s("%d", &n);
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &m[b]);
		}
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &g[b]);
		}
		quickSort(m, 0, n - 1);
		quickSort(g, 0, n - 1);
		for (int b = 0;b < n;b++) {
			sum += abs(g[b] - m[b]);
		}
		printf("%d\n", sum);
	}
}