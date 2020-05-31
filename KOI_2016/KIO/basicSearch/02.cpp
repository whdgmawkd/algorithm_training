#include <stdio.h>

int main(void) {
	int n;
	scanf_s("%d", &n);
	for (int a = 1;a <= n;a++) {
		if (a % 3 == 0)
			printf("X ");
		else
			printf("%d ", a);
	}
	return 0;
}