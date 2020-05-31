#include <stdio.h>
void quickSort(int* arr, int left, int right) {
	int l = left, r = right;
	int pivot = arr[(l + r) / 2];
	while (l <= r) {
		while (arr[l] < pivot)
			l++;
		while (pivot < arr[r])
			r--;
		if (l <= r) {
			int tmp = arr[r];
			arr[r] = arr[l];
			arr[l] = tmp;
			l++;
			r--;
		}
	}
	if (left < r)
		quickSort(arr, left, r);
	if (l < right)
		quickSort(arr, l, right);
}
int main(void) {
	int n;
	int A[50], B[50];
	int sum = 0;
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", A + a);
	}
	for (int a = 0;a < n;a++) {
		scanf_s("%d", B + a);
	}
	quickSort(A, 0, n - 1);
	quickSort(B, 0, n - 1);
	for (int a = 0;a < n;a++) {
		sum += (A[a] * B[n - 1 - a]);
	}
	printf("%d\n", sum);
}