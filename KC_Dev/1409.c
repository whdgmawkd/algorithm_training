#include <stdio.h>
#include <string.h>
#include "base.h"

char stack[26];
int stackIdx;
char str[27];

void push(char);
char pop();
char peek();

int main(void) {
	int strIdx = 0;
	char alpha = 'a';
	printf("Input : ");
	scanf_s("%s", str, 27);
	printFirst();
	while (1) {
		if (strIdx == strlen(str)) {
			return 0;
		}
		if (alpha > 'z') {
			printf("Impossible\n");
			return -1;
		}
		if (peek() > str[strIdx]) {
			printf("Impossible\n");
			return -1;
		}
		if (peek() == str[strIdx]) {
			printf("pop %c\n", str[strIdx]);
			pop();
			strIdx++;
		}
		else if (peek() < str[strIdx]) {
			printf("push %c\n", alpha);
			push(alpha);
			alpha++;
		}
		
	}
}

void push(char c) {
	stack[stackIdx] = c;
	stackIdx++;
}

char pop() {
	char popRst = stack[stackIdx-1];
	stackIdx--;
	return popRst;
}

char peek() {
	return stack[stackIdx-1];
}
