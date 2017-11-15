#define __CASE16_FAILED_TIMEOUT__
#include <stdio.h>

int op[100005][3];
int bead[1000005];
int opCnt, beadCnt;

void printRange(int, int);
void setBead(int, int);

int main(void) {
	scanf_s("%d %d", &beadCnt, &opCnt);
	for (int a = 1;a <= beadCnt;a++) {
		scanf_s("%d", bead + a);
	}
	for (int a = 0;a < opCnt;a++) {
		scanf_s("%d %d %d", op[a], op[a] + 1, op[a] + 2);
	}
	for (int a = 0;a < opCnt;a++) {
		if (op[a][0] == 1)
			printRange(op[a][1], op[a][2]);
		else
			setBead(op[a][1], op[a][2]);
	}
	return 0;
}

void printRange(int s, int e) {
	int sum = 0;
	for (int a = s;a <= e;a++) {
		sum += bead[a];
	}
	printf("%d\n", sum);
}

void setBead(int index, int num) {
	bead[index] = num;
}