#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"

int graph[10];
char data[16];
int maxHeight;

int main(void) {
	printf("N : ");
	scanf_s("%s", data, 16);
	printFirst();
	if (strlen(data) > 15) {
		printf("Too long Data Lenth\n");
		return -1;
	}
	for (int a = 0;a < strlen(data);a++) {
		graph[data[a] - '0']++;
	}
	for (int a = 0;a < 10;a++) {
		if (graph[a] > maxHeight) {
			maxHeight = graph[a];
		}
	}
	for (int a = maxHeight;a > 0;a--) {
		for (int b = 0;b < 10;b++) {
			if (graph[b] >= a) {
				printf(" * ");
			}
			else {
				printf(" - ");
			}
		}
		printf("\n");
	}
	printf("------------------------------\n");
	printf(" 0  1  2  3  4  5  6  7  8  9 \n");
	return 0;
}