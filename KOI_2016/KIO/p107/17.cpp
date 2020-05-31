#include <stdio.h>

int budget;
int actCnt;
int actCost[22];
int max;

int input() {
	scanf_s("%d", &budget);
	scanf_s("%d", &actCnt);
	for (int a = 0;a < actCnt;a++) {
		scanf_s("%d", &actCost[a]);
	}
	return 0;
}

void findMaximum(int act, int total) {
	if (act == actCnt + 1) {
		if (total <= budget && total > max) {
			max = total;
		}
		return;
	}
	findMaximum(act + 1, total); // exclude act
	findMaximum(act + 1, total + actCost[act]); // include act
}

int main(void) {
	input();
	findMaximum(0, 0);
	printf("%d", max);
	return 0;
}