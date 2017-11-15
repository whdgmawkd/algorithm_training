#include <stdio.h>
#include "base.h"

int weight;

int weightArr[11] = { 1,2,4,8,16,32,64,128,256,512,1024 };
int weightNeed[11];

int main(void) {
	printf("Input : ");
	scanf_s("%d", &weight);
	printFirst();
	if (weight >= 2048) {
		printf("Invalid Weight\n");
		return -1;
	}
	for (int index = 10;index >= 0;index--) {
		if (weight >= weightArr[index]) {
			weight -= weightArr[index];
			weightNeed[index]++;
		}
	}
	printf("Needed weight: ");
	for (int a = 0;a < 10;a++) {
		if(weightNeed[a]==1)
			if (a == 0) {
				printf("%d(%dg)", a, weightArr[a]);
			}
			else
			{
				printf(", %d(%dg)", a, weightArr[a]);
			}
	}
	printf("\n");
	return 0;
}