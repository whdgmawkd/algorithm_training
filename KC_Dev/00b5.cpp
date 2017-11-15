#include <stdio.h>
int n, wCnt, bCnt;
int arr[64][64];
void divArr(int, int, int, int);
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++)
		for (int b = 0;b < n;b++)
			scanf_s("%d", &arr[a][b]);
	divArr(0, 0, n - 1, n - 1); //first
	printf("%d\n%d\n", wCnt, bCnt);
	return 0;
}
void divArr(int x1, int y1, int x2, int y2) {
	int master = arr[x1][y1];
	int neq = 0;
	for (int a = x1;a <= x2;a++) {
		for (int b = y1;b <= y2;b++) {
			if (arr[a][b] != master) {
				neq = 1;
				break;
			}
		}
		if (neq)
			break;
	}
	if (neq&&x2-x1>=0&&y2-y1>=0) { // holy shit code
		divArr(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2); //left top
		divArr((x1 + x2) / 2+1, (y1 + y2) / 2+1, x2, y2); // right bottom
		divArr((x1 + x2) / 2+1, y1, x2, (y1 + y2) / 2); // right top
		divArr(x1, (y1 + y2) / 2+1, (x1 + x2) / 2, y2); // left bottom
	}
	if (!neq) {
		if (master == 1)
			bCnt++;
		else
			wCnt++;
	}
}