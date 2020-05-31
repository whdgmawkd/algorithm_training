#include <stdio.h>
int divisor[1000];
int divisorCnt;
int n, m;
int exit;
void getDivisor(int n) {
	int a;
	for (a = 1;a < n;a++) {
		if (n%a == 0) {
			divisor[divisorCnt++] = a;
		}
	}
}
void weird(int sum, int divIndex) {
	if (exit >= 1) {
		return;
	}
	if (sum == m) {
		exit = 1;
		printf("not weird\n");
		return;
	}
	if (divIndex == divisorCnt) {
		return;
	}
	weird(sum, divIndex + 1);
	weird(sum + divisor[divIndex], divIndex + 1);
}
void getSum() {
	int sum = 0;
	for (int a = 0;a < divisorCnt;a++) {
		sum += divisor[a];
	}
	weird(0, 0);
	if (exit == 0) {
		if (sum > m) {
			printf("weird\n");
			return;
		}
		else
			printf("not weird\n");
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%d", &m);
		divisorCnt = 0;
		getDivisor(m);
		getSum();
		exit = 0;
	}
	return 0;
}