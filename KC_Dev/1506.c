#include <stdio.h>
#include "base.h"

int main(void) {
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	printFirst();
	printf("%d\n", (a - 2) * 4 + (b - 2) * 6 + (c - 2) * 2);
	return 0;
}