#include <stdio.h>
#include <string.h>
int n;
char str[101];
void print() {
	int len = strlen(str);
	for (int a = 0;a < len;a += 2)
		printf("%c", str[a]);
	for (int a = 1;a < len;a += 2)
		printf("%c", str[a]);
	printf("\n");
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s", str, 100);
		print();
	}
}