#include <stdio.h>
#include "base.h"
#include <string.h>
#include <stdlib.h>

int arr[10] = { 12,34,7,56,24,87,9,42,66,23 };
int k;

void printArray();
void sortArray();

int main(void) {
	printf("K: ");
	scanf_s("%d", &k);
	printFirst();
	printf("배열 : ");
	printArray();
	sortArray();
	printf("\n정렬 : ");
	printArray();
	printf("\n%d번째 큰수 : %d\n",k, arr[k - 1]);
	printf("%d번째 작은수 : %d\n",k, arr[10 - k]);
	printf("두 수의 차 : %d\n", arr[10 - k] - arr[k - 1]);
	return 0;	
}

void printArray() {
	for (int a = 0;a < 10;a++) {
		if (a == 0)
			printf("%d", arr[a]);
		else
			printf(", %d", arr[a]);
	}
}

void sortArray() {
	int tmp;
	int min;
	for (int a = 0;a < 9;a++) {
		min = a;
		for (int b = a + 1;b < 10;b++) {
			if (arr[min] > arr[b]) {
				min = b;
			}
		}
		tmp = arr[min];
		arr[min] = arr[a];
		arr[a] = tmp;
	}
}