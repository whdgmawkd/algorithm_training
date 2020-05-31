#include "base.h"
#include <stdio.h>
#include <stdlib.h>

int i, j;

int getCycle(int num, int cycle);

int main(void) {
	printf("Input i, j : ");
	scanf_s("%d %d", &i, &j);
	printFirst();
	int iCnt = getCycle(i, 1);
	int jCnt = getCycle(j, 1);
	printf("%d %d\n", i, iCnt);
	printf("%d %d\n", j, jCnt);
	if (iCnt > jCnt) {
		printf("%d %d\n", i, iCnt - jCnt);
	}
	else {
		printf("%d %d\n", j, jCnt - iCnt);
	}
	return 0;
}

int getCycle(int num, int cycle) {
	if (num == 1) {
		return cycle;
	}
	if (num % 2 == 0) {
		getCycle(num / 2, cycle + 1);
	}
	else {
		getCycle(num * 3 + 1, cycle + 1);
	}
}
