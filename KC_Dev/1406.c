#include <stdio.h>
#include <string.h>
#include "base.h"

char strNum[21];

int incCnt;
int decCnt;

int findInc();
int findDec();

int main(void) {
	scanf_s("%s", strNum, 22);
	incCnt = findInc();
	decCnt = findDec();
	if (incCnt > decCnt) {
		printf("Increase Numberic: %d\n", incCnt);
	}
	else if (incCnt < decCnt) {
		printf("Decrease Numberic: %d\n", decCnt);
	}
	else if (incCnt == decCnt) {
		printf("Numberic Lenth Equal: %d\n", incCnt);
	}
	return 0;
}

int findInc() {
	int cnt=2;
	int tmp=1;
	for (int a = 1;a < strlen(strNum);a++) {
		if (strNum[a] >= strNum[a - 1]) {
			tmp++;
		}
		else if (strNum[a] < strNum[a - 1]) {
			if (tmp > cnt)
				cnt = tmp;
			tmp = 1;
		}
	}
	return cnt;
}

int findDec() {
	int cnt = 2;
	int tmp = 1;
	for (int a = 1;a < strlen(strNum);a++) {
		if (strNum[a] <= strNum[a - 1]) {
			tmp++;
		}
		else if (strNum[a] > strNum[a - 1]) {
			if (tmp > cnt)
				cnt = tmp;
			tmp = 1;
		}
	}
	return cnt;
}