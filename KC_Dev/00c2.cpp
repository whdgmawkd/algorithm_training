#define __RETIRE__
#define __CASE2_FAILED__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[2001];
char rst[2001];
int len;
int rstIndex;

int solve(int left, int right);

int main(void) {
	scanf_s("%d", &len);
	scanf_s("%s", str, 2001);
	solve(0, len - 1);
	printf("%s", rst);
	return 0;
}

int solve(int left, int right) {
	while (left <= right) {
		if (str[left] < str[right])
			rst[rstIndex++] = str[left++];
		else if (str[left]>str[right])
			rst[rstIndex++] = str[right--];
		else {
			if (str[left + 1] < str[right - 1])
				rst[rstIndex++] = str[left++];
			else 
				rst[rstIndex++] = str[right--];
		}
	}
	return 0;
}