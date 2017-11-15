#include <stdio.h>
int sw[10][5] = {
	{0,1,2,-1,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15,-1},
	{3,14,15,-1,-1},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13} };
int clock[16];
int n, cnt=0x7fffffff;
int checkClock() {
	for (int a = 0;a < 16;a++) {
		if (clock[a] != 12)
			return 1;
	}
	return 0;
}
void syncClock(int count,int prev) {
	for (int a = 0;a < 16;a++) {
		printf("%d ", clock[a]);
	}
	printf("\n");
	if (count > cnt) {
		return;
	}
	if (checkClock() == 0) {
		if (count < cnt) {
			cnt = count;
			return;
		}
	}
	if (clock[14] != clock[15] || clock[8] != clock[12]) {
		cnt = -1;
		return;
	}
	for (int a = 0;a < 10;a++) {
		for (int b = 0;b < 5;b++) {
			if (sw[a][b] == -1)
				continue;
			if (clock[sw[a][b]] == 12)
				clock[sw[a][b]] = 0;
			clock[sw[a][b]] += 3;
		}
		syncClock(count + 1,a);
		for (int b = 0;b < 5;b++) {
			if (sw[a][b] == -1)
				continue;
			if (clock[sw[a][b]] == 3)
				clock[sw[a][b]] = 15;
			clock[sw[a][b]] -= 3;
		}
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < 16;b++) {
			scanf_s("%d", &clock[b]);
		}
		syncClock(0,-1);
		printf("%d\n", cnt);
		cnt = 0x7fffffff;
	}
}