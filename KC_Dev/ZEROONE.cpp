#include <stdio.h>
#include <string.h>
char num[1000001];
int acc[1000000];
int n, s, e, tmp, exit;
int main(void) {
	gets_s(num, 1000000);
	scanf_s("%d", &n);
	int len = strlen(num);
	for (int a = 0;a < len - 1;a++) {
		if (num[a] != num[a + 1]) {
			acc[a+1] = ++tmp;
		}
		else {
			acc[a+1] = tmp;
		}
	}
	for (int a = 0;a < n;a++) {
		exit = 0;
		scanf_s("%d %d", &s, &e);
		if (acc[s] != acc[e]) {
			puts("No");
		}
		else {
			puts("Yes");
		}
	}
}