#define __RETIRE__
#include "lib.h"
#include <stdio.h>
int k, findX=-1, findY=-1;
void matrixSearch(int, int, int, int);
int main(void) {
	scanf_s("%d", &k);
	matrixSearch(1, 1, 5, 5);
	printf("%d %d", findX, findY);
	return 0;
}
void matrixSearch(int x1, int y1, int x2, int y2) { // ex k=4
	int midX = (x1 + x2) / 2;
	int midY = (y1 + y2) / 2;

}
int function(int x, int y) {
	int arr[5][5] = { 
	{ 1, 3, 5,  6,  7 },
	{ 2, 4, 7,  7,  9 }, 
	{ 3, 5, 8,  9,  10 },
	{ 4, 6, 9,  13, 13 },
	{ 5, 7, 10, 19, 20 } 
	};
	return arr[x - 1][y - 1];
}