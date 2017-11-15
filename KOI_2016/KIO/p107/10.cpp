#include <stdio.h>

int arr[10][10];
int n;
int min = 0x7fffffff;
int check[10];

void f(int row,int score) {
	if (row == n) {
		if (score < min)
			min = score;
		return;
	}
	for (int a = 0;a < n;a++) {
		if (check[a] == 0) {
			check[a] = 1;
			f(row + 1, score + arr[row][a]);
			check[a] = 0;
		}
	}
	return;
}

int input() {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		for (int b = 0;b < n;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	return 0;
}

int main(void) {
	input();
	f(0, 0);
	printf("%d\n", min);
	return 0;
}