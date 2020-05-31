#include <stdio.h>
#include <algorithm>

int n, k;
int arr[1000001];

int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &arr[a]);
	}
	scanf_s("%d", &k);
	printf("%d\n", std::lower_bound(arr, arr + n,k)-arr+1);
	return 0;
}