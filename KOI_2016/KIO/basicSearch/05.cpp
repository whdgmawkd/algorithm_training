#include <stdio.h>
#include <algorithm>

int arr[100001];
int n, k;

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &arr[a]);
	}
	scanf_s("%d", &k);
	printf("%d\n", std::upper_bound(arr, arr + n, k)-arr+1);
	return 0;
}