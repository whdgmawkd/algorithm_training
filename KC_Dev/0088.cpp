#include <stdio.h>
int n, k, arr[100001];
int main(void) {
	scanf_s("%d %d", &n, &k);
	for (int a = 0;a < n;a++) scanf_s("%d", arr + a);
	for (int a = 0;a < n;a++) {
		if (arr[a] == k) {
			printf("%d\n", a + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}