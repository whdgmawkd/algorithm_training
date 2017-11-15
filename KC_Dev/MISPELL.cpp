#include <stdio.h>
#include <string.h>
int n,k;
char str[1001];
int main(void) {
	scanf_s("%d", &n);
	for (int a = 1;a <= n;a++) {
		scanf_s("%d %s", &k, str,1000);
		printf("%d ", a);
		for (int b = 0;b < strlen(str);b++) {
			if (b == k - 1)
				continue;
			printf("%c", str[b]);
		}
		printf("\n");
	}
}