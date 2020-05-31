#include <stdio.h>
int name[51];
int n;
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s", name, 50);
		printf("Hello, %s!\n", name);
	}
	return 0;
}