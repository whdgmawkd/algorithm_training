#include <stdio.h>
#include <vector>

using namespace std;

int objCnt;
int packLimit;
int max=0x80000000;
typedef struct _objInfo {
	int weight;
	int value;
} objINFO;
objINFO objArr[101];

int getMax(int arg1, int arg2) {
	return arg1 > arg2 ? arg1 : arg2;
}

int findMax(int index, int weight) {
	if (index == objCnt + 1) {
		return 0;
	}
	else if (weight < objArr[index].weight) {
		return findMax(index + 1, weight); // exclude objArr[index]. it is too heavy
	}
	else {
		return getMax(findMax(index + 1, weight), findMax(index + 1, weight - objArr[index].weight) + objArr[index].value); // arg1 -> exclude index. arg2 -> include index.
	}
}

int main(void) {
	scanf_s("%d %d", &objCnt, &packLimit);
	for (int a = 0;a < objCnt;a++) {
		scanf_s("%d %d", &objArr[a].weight, &objArr[a].value);
	}
	printf("%d\n", findMax(0, packLimit));
	return 0;
}
