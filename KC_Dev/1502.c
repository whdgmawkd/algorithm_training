#include <stdio.h>
#include "base.h"

int changeType[3] = { 100,50,10 };
int changeCnt[3];
int cost;

int calcChange(int change);
void printFirst();
int printChange();

int main(void) {
	printf("물건값: ");
	scanf_s("%d", &cost);
	printFirst();
	if (cost > 1000) {
		printf("금액 초과\n");
		return 1;
	}
	calcChange(1000 - cost);
	printChange();
	return 0;
}

int calcChange(int change) {
	if (change <= 0) {
		return 0;
	}
	for (int a = 0;a < 3;a++) {
		if (change >= changeType[a]) {
			changeCnt[a]++;
			calcChange(change - changeType[a]);
			break;
		}
	}
}

int printChange() {
	for (int a = 0;a < 3;a++) {
		printf("%d원: %d개\n", changeType[a], changeCnt[a]);
	}
	return 0;
}