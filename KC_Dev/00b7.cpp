#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char aNum[1005];
char bNum[1005];
int sum[105];
int sumIndex, prev;
int Add(char a[], char b[], int result[]);
int Sub(char a[], char b[], int result[]);
int main(void) {
	scanf_s("%s", aNum, 1004);
	scanf_s("%s", bNum, 1004);
	if (aNum[0] == '-'&&bNum[0] == '-') {
		printf("-");
		Add(aNum + 1, bNum + 1, sum);
	}
	else if (aNum[0] == '-')
		Sub(bNum, aNum, sum);
	else if (bNum[0] == '-')
		Sub(aNum, bNum, sum);
	else
		Add(aNum, bNum, sum);
	for (int a = sumIndex;a >= 0;a--) {
		if (prev==0&&sum[a]==0)
			continue;
		prev = 1;
		printf("%d", sum[a]);

	}
}
int Add(char a[], char b[], int result[]) {
	int aIndex = strlen(a)-1;
	int bIndex = strlen(b)-1;
	int maxIndex = aIndex > bIndex ? aIndex + 1 : bIndex + 1;
	while (1) {
		if (sumIndex >= maxIndex)
			break;
		if (aIndex >= 0 && bIndex >= 0)
			sum[sumIndex++] = (a[aIndex--] - '0') + (b[bIndex--] - '0');
		else if (aIndex >= 0)
			sum[sumIndex++] = a[aIndex--] - '0';
		else if (bIndex >= 0)
			sum[sumIndex++] = b[bIndex--] - '0';
	}
	for (int a = 0;a < sumIndex;a++) {
		if (sum[a] >= 10) {
			sum[a + 1]++;
			sum[a] -= 10;
		}
	}
	return 0;
}
int Sub(char a[], char b[], int result[]) {
	int aIndex = strlen(a) - 1;
	int bIndex = strlen(b) - 1;
	int maxIndex = aIndex > bIndex ? aIndex + 1 : bIndex;
	while (1) {
		if (sumIndex >= maxIndex)
			break;
		if (aIndex >= 0 && bIndex >= 1)
			sum[sumIndex++] = (a[aIndex--] - '0') - (b[bIndex--] - '0');
		else if (aIndex >= 0)
			sum[sumIndex++] = a[aIndex--] - '0';
		else if (bIndex >= 1)
			sum[sumIndex++] = b[bIndex--] - '0';
	}
	if (strlen(a) < strlen(b)-1&&a[0]<b[1])
		printf("-");
	for (int a = 0;a < sumIndex;a++) {
		if (sum[a] < 0) {
			sum[a + 1]--;
			sum[a] += 10;
		}
	}
	return 0;
}