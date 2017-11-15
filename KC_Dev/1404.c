#include <stdio.h>
#include "base.h"

int h, w;

int arr[20][20];

int main(void) {
	printf("N : ");
	scanf_s("%d %d", &h, &w);
	printFirst();
	for (int a = 0;a < 20;a++) {
		arr[a][0] = 1;
		arr[0][a] = 1;
	}
	for (int a = 1;a < h;a++) {
		for (int b = 1;b < w;b++) {
			arr[a][b] = arr[a - 1][b] + arr[a][b - 1];
		}
	}
	for (int a = 0;a < h;a++) {
		for (int b = 0;b < w;b++) {
			printf("%d ", arr[a][b]);
		}
		printf("\n");
	}
	return 0;
}