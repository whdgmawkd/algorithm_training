#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

int arr[6];
int allnum[2000];
int alli;

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int compare(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int chk(int n) {
	int a;
	if (n == 1) {
		return -1;
	}
	for (a = 2;a*a < n;a++) {
		if (n%a == 0) {
			return -1;
		}
	}
	if (a*a == n) {
		return -1;
	}
	return 0;
}

void P(int i, int last) {
	int num = 0;
	if (i == last) {
		for (int a = 0;a <= last;a++) {
			num += arr[a] * (int)pow((double)10, (double)a);
		}
		allnum[alli++] = num;
	}
	else {
		for (int a = i;a <= last;a++) {
			swap(arr + i, arr + a);
			P(i + 1, last);
			swap(arr + i, arr + a);
		}
	}
}

int main(void) {
	int n, last, prev = -1;
	scanf_s("%d", &n);
	for (int a = 0;a < 6;a++) {
		if (n != 0) {
			arr[a] = n % 10;
			n /= 10;
			last = a;
		}
	}
	P(0, last);
	std::qsort(allnum, alli, sizeof(int), compare);
	for (int a = 0;a < alli;a++) {
		if (chk(allnum[a]) == 0) {
			if (prev != allnum[a]) {
				printf("%d ", allnum[a]);
				prev = allnum[a];
			}
		}
	}
	if (prev == -1) {
		printf("0");
	}
	return 0;
}