#include <stdio.h>
#include <algorithm>
int arr[100001];
int n;
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++)
		scanf_s("%d", arr + a);
	std::sort(arr, arr + n);
	for (int a = n - 1;a >= 0;a--)
		printf("%d ", arr[a]);
	return 0;
}