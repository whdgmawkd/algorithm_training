#include <stdio.h>
#include <string.h>
#include "base.h"

int opCnt;

int Board[101][101];

char opText[10][6];
int opArgs[10][3];

void fill(int x, int y,int range, int color);
int getBoard(int x, int y,int range, int color);

int main(void) {
	printf("Input : ");
	scanf_s("%d", &opCnt);
	printFirst();
	for (int a = 0;a < opCnt;a++) {
		scanf_s("%s", opText[a],7);
		scanf_s("%d %d %d", &opArgs[a][0], &opArgs[a][1], &opArgs[a][2]);
	}
	fill(1, 1, 100, 0);
	for (int a = 0;a < opCnt;a++) {
		int x, y, l;
		x = opArgs[a][0];
		y = opArgs[a][1];
		l = opArgs[a][2];
		if (strcmp(opText[a], "WHITE") == 0) {
			fill(x, y, l, 0);
		}
		else if (strcmp(opText[a], "BLACK") == 0) {
			fill(x, y, l, 1);
		}
		else if (strcmp(opText[a], "TESTB") == 0) {
			printf("%d\n", getBoard(x, y, l, 1));
		}
		else if (strcmp(opText[a], "TESTW") == 0) {
			printf("%d\n", getBoard(x, y, l, 0));
		}
	}
	return 0;
}

void fill(int x, int y, int l, int color) {
	for (int a = x;a < x + l;a++) {
		for (int b = y;b < y + l;b++) {
			Board[a][b] = color;
		}
	}
}

int getBoard(int x, int y, int l, int color) {
	int cnt = 0;
	for (int a = x;a < x + l;a++) {
		for (int b = y;b < y + l;b++) {
			if (Board[a][b] == color) {
				cnt++;
			}
		}
	}
	return cnt;
}