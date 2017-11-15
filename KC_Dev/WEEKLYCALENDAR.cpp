#include <stdio.h>
#include <string.h>
int DAY_OF_MONTH[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
char DAY[7][15] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
int n, month, dayOfMonth;
char day[15];
void drawCal(int m, int dOm, char *d) {
	int dIndex=0,cur;
	for (int a = 0;a < 7;a++) {
		if (strcmp(d, DAY[a]) == 0)
			dIndex = a;
	}
	if (dOm - dIndex < 1) {
		if (m - 1 <= 0) {
			m = 12;
		}
		else {
			m = m - 1;
		}
		cur = DAY_OF_MONTH[m - 1] + (dOm - dIndex);
	}
	else {
		cur = dOm - dIndex;
	}
	for (int a = 0;a < 7;a++) {
		if (cur > DAY_OF_MONTH[m - 1]) {
			cur = 1;
			m = m + 1;
		}
		printf("%d ", cur);
		cur++;
	}
	printf("\n");
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d %d %s", &month, &dayOfMonth, day, 15);
		drawCal(month, dayOfMonth, day);
	}
}