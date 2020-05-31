#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[1001];
int n;
void print(void) {
	int len = strlen(str);
	int minIndex = 0;
	for (int a = 0;a < len;a+=2) {
		for (int b = 0;b < len;b += 2) {
			if (str[minIndex] > str[b]) {
				minIndex = b;
			}
			else if (str[minIndex] == str[b]&&str[minIndex+1]>str[b+1]) {
				minIndex = b;
			}
		}
		printf("%c%c", str[minIndex], str[minIndex + 1]);
		str[minIndex] = str[minIndex + 1] = 'z' + 1;
	}
	printf("\n");
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s", str, 1000);
		print();
	}
}