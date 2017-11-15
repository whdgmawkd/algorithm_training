#include <stdio.h>
#include "base.h"

int getMiddleNumber(int number);
int printExp(int number, int rightMax);
int number;

int main(void) {
	printf("입력: ");
	scanf_s("%d", &number);
	printFirst();
	if (number > 1000) {
		printf("입력 오류\n");
		return -1;
	}
	getMiddleNumber(number);
	return 0;
}

int getMiddleNumber(int number) {
	int left = 0;
	int right = 0;
	int tmp = number + 1;
	for (int a = 1;a < number;a++) {
		left += a;
	}
	while (right < left) {
		right += tmp;
		tmp++;
		if (right == left) {
			printf("%d은 중간수 입니다\n", number);
			printExp(number, tmp);
			return tmp;
		}
	}
	printf("%d은 중간수가 아닙니다.\n", number);
	return -1;
}

int printExp(int number, int rightMax) {
	int left = 0;
	int right = 0;
	for (int a = 1;a < number;a++) {
		if (a == 1)
			printf("1");
		else
			printf("+%d", a);
		left += a;
	}
	printf(" = %d\n", left);
	for (int a = number + 1;a < rightMax;a++) {
		if (a == number + 1)
			printf("%d", a);
		else
			printf("+%d", a);
		right += a;
	}
	printf(" = %d\n", right);
	return 0;
}