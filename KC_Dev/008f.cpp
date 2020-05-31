#include <stdio.h>
int arr[100001], n;
void quickSort(int left, int right) {
	int l = left, r = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (l <= r) {
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r) {
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			l++;
			r--;
		}
	}
	if (left < r)
		quickSort(left, r);
	if (l < right)
		quickSort(l, right);
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) scanf_s("%d", arr + a);
	quickSort(0, n - 1);
	for (int a = 0;a < n;a++) printf("%d ", arr[a]);
	return 0;
}