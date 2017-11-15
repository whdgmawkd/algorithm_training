#include <stdio.h>
int a, b, t;
int main(void) {
	scanf_s("%d", &t);
	while (t--) {
		scanf_s("%d %d", &a, &b);
		if (a > b) {
			printf("0\n");
			continue;
		}
		printf("%d\n", 4 + b - a);
	}
}