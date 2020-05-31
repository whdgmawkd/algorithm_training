#include <stdio.h>
int a, n, s, arr[1000001];
int main(void) {
	scanf_s("%d %d", &n, &s);
	for (a = 0;a < n;a++)
		scanf_s("%d", arr + a);
	for (a = 0;a < n;a++) {
		if (arr[a] == s) {
			printf("%d\n", a + 1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}