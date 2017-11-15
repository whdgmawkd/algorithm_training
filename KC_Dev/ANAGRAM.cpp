#include <stdio.h>
#include <string.h>
char left[101];
char right[101];
int leftSum, rightSum, t;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%s", left, 100);
		scanf_s("%s", right, 100);
		if (strcmp(left, right) == 0) {
			printf("No.\n");
		}
		else if (strlen(left) != strlen(right)) {
			printf("No.\n");
		}
		else {
			int len = strlen(left);
			for (int b = 0;b < len;b++) {
				leftSum += left[b];
				rightSum += right[b];
			}
			if (leftSum == rightSum) {
				printf("Yes\n");
			}
			else {
				printf("No.\n");
			}
		}
		leftSum = rightSum = 0;
	}
}