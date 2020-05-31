#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>

char magicStr[12];
char devil[22];
char angel[22];

int solve(int sw, int bridgeIndex, int magicIndex) {
	int count = 0;
	if (magicStr[magicIndex] == '\0') {
		return 1;
	}
	if (sw == 0) {
		for (int a = bridgeIndex;devil[a]!='\0';a++) {
			if (devil[a] == magicStr[magicIndex]) {
				printf("0 : %c,%d\n", devil[a],a);
				count += solve(1, a + 1, magicIndex + 1);
			}
		}
	}
	if (sw == 1) {
		for (int a = bridgeIndex;angel[a]!='\0';a++) {
			if (angel[a] == magicStr[magicIndex]) {
				printf("1 : %c,%d\n", angel[a],a);
				count += solve(0, a + 1, magicIndex + 1);
			}
		}
	}
	return count;
}

int main(void) {
	scanf_s("%s", magicStr, 12);
	scanf_s("%s", devil, 22);
	scanf_s("%s", angel, 22);
	printf("%d\n", solve(0, 0, 0));
	printf("%d\n", solve(1, 0, 0));
	return 0;
}