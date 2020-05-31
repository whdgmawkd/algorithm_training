#include <stdio.h>
#include "base.h"
#include <stdlib.h>
#include <string.h>

char str[6][100];
int strCnt;

int main(void) {
	scanf_s("%d", &strCnt);
	for (int a = 0;a < strCnt;a++) {
		scanf_s("%s", str[a], 100);
	}
	printFirst();
	for (int a = 0;a < strCnt;a++) {
		for (int b = 0;b < strlen(str[a]);b += 2) {
			printf("%c", str[a][b]);
		}
		for (int b = 1;b < strlen(str[a]);b += 2) {
			printf("%c", str[a][b]);
		}
		printf("\n");
	}
	return 0;
}
