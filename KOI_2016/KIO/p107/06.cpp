#include <stdio.h>

int arr[21][21]; // 19+2

// search left to right
int search1(int, int, int, int);

// search leftup to rightdown
int search2(int, int, int, int);

// search up to down
int search3(int, int, int, int);

// search lefdown to rightup
int search4(int, int, int, int);

int main(void) {
	for (int a = 1;a <= 19;a++) {
		for (int b = 0;b <= 19;b++) {
			scanf_s("%d", &arr[a][b]);
		}
	}
	for (int a = 1;a <= 19;a++) {
		for (int b = 0;b <= 19;b++) {
			if (arr[a][b] != 0) {
				if (arr[a][b - 1] != arr[a][b] && search1(arr[a][b], a, b, 1) == 1) {
					printf("%d\n%d %d", arr[a][b], a, b);
					return 0;
				}
				if (arr[a - 1][b - 1] != arr[a][b] && search2(arr[a][b], a, b, 1) == 1) {
					printf("%d\n%d %d", arr[a][b], a, b);
					return 0;
				}
				if (arr[a - 1][b - 1] != arr[a][b] && search3(arr[a][b], a, b, 1) == 1) {
					printf("%d\n %d %d", arr[a][b], a, b);
					return 0;
				}
				if (arr[a + 1][b - 1] != arr[a][b] && search4(arr[a][b], a, b, 1) == 1) {
					printf("%d\n %d %d", arr[a][a], a, b);
					return 0;
				}
			}
		}
	}
	printf("0");
	return 0;
}

int search1(int color, int a, int b, int cnt) {
	for (;color == arr[a][b + 1];b++) {
		cnt++;
	}
	return cnt == 5 ? 1 : 0;
}

int search2(int color, int a, int b, int cnt) {
	for (;color == arr[a + 1][b + 1];a++, b++) {
		cnt++;
	}
	return cnt == 5 ? 1 : 0;
}

int search3(int color, int a, int b, int cnt) {
	for (;color == arr[a + 1][b];a++) {
		cnt++;
	}
	return cnt == 5 ? 1 : 0;
}

int search4(int color, int a, int b, int cnt) {
	for (; color == arr[a - 1][b + 1];a++, b--) {
		cnt++;
	}
	return cnt == 5 ? 1 : 0;
}
