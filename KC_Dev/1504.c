#include <stdio.h>
#include "base.h"

int ball[3][3];
int popRst[6];
int popIdx;


int main(void) {
	for (int a = 0;a < 3;a++) {
		for (int b = 0;b < 3 - a;b++) {
			scanf_s("%d", &ball[a][b]);
		}
	}
	printFirst();
	for (int a = 0;a < 3;a++) {
		for (int b = 0;b < 3 - a;b++) {
			if (ball[a][b] < 1 || ball[a][b]>6) {
				printf("형식 오류\n");
				return -1;
			}
		}
	}
	while (1) {
		if (ball[2][0] == 0)
			break;
		popRst[popIdx] = ball[2][0];
		popIdx++;
		ball[2][0] = 0;
		if (ball[1][0]>ball[1][1]) {
			ball[2][0] = ball[1][0];
			ball[1][0] = 0;
			if (ball[0][0]>ball[0][1]) {
				ball[1][0] = ball[0][0];
				ball[0][0] = 0;
			}
			else {
				ball[1][0] = ball[0][1];
				ball[0][1] = 0;
			}
		}
		else {
			ball[2][0] = ball[1][1];
			ball[1][1] = 0;
			if (ball[0][1] > ball[0][2]) {
				ball[1][1] = ball[0][1];
				ball[0][1] = 0;
			}
			else {
				ball[1][1] = ball[0][2];
				ball[0][2] = 0;
			}
		}
	}
	for (int a = 0;a < 6;a++) {
		printf("%d ", popRst[a]);
	}
	printf("\n");
}