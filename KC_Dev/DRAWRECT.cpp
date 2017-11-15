#include <stdio.h>
int testCase;
int pointx[3];
int pointy[3];
int xindex,yindex;
void input() {
	for (int a = 0;a < 3;a++)
		scanf_s("%d %d", &pointx[a], &pointy[a]);
}
void print() {
	int x = 0, y = 0;
	for (int a = 0;a < 3;a++) {
		x ^= pointx[a];
		y ^= pointy[a];
	}
	printf("%d %d\n", x, y);
}
int main(void) {
	scanf_s("%d", &testCase);
	for (int a = 0;a < testCase;a++) {
		input();
		print();
	}
	return 0;
}