#include <stdio.h>

int x, y;
int arr[10][10];
int max=-123456789;

void search(void);
void input(void);

int main(void) {
	input();
	search();
	printf("%d %d\n", x+1, y+1);
	return 0;
}

void search(void) {
	for (int a = 0;a < 9;a++) {
		for (int b = 0;b < 9;b++) {
			if (arr[a][b] > max) {
				max = arr[a][b];
				x = a;
				y = b;
			}
		}
	}
}

void input() {
	for (int a = 0;a < 9;a++) {
		for (int b = 0;b < 9;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
}

