#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

char num[10];

int getRunaroundNum(char* num);

int main(void) {
	scanf_s("%s", num, 10);
	printFirst();
	if (strlen(num) > 9 || strlen(num) < 5) {
		printf("입력 오류");
		return -1;
	}
	getRunaroundNum(num);
	return 0;
}

int getRunaroundNum(char* num) {
	while (1) {
		int cnt = 0;
		for (int a = 0;a < strlen(num);a++) {
			cnt += num[a] - '0';
		}
		if (cnt%strlen(num) == 0) {
			printf("%s\n", num);
			return 0;
		}
		int tmp = atoi(num);
		tmp += 1;
		sprintf_s(num, 10, "%d", tmp);
	}
}