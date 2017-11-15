#include <stdio.h>
#include <string.h>
int n;
char str[10001];
char Stack[10001];
int stackIndex = 0;
int evalBracket(char bracket) {
	switch (bracket) {
	case '(':
		return 1;
	case '{':
		return 2;
	case '[':
		return 3;
	case ']':
		return 4;
	case '}':
		return 5;
	case ')':
		return 6;
	default :
		return 0;
	}
}
char pop() {
	if (stackIndex < 1)
		return 0;
	return Stack[--stackIndex];
}
void push(char bracket) {
	Stack[stackIndex++] = bracket;
}
char peek() {
	return Stack[stackIndex - 1];
}
void evalStr() {
	int len = strlen(str);
	int index = 0;
	while (index < len) {
		push(str[index]);
		if (evalBracket(peek())>3) {
			if (evalBracket(pop()) == 7 - evalBracket(peek())) {
				pop();
			}
			else {
				printf("NO\n");
				return;
			}
		}
		index++;
	}
	if (stackIndex > 0)
		printf("NO\n");
	else
		printf("YES\n");
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s", str, 10000);
		evalStr();
		stackIndex = 0;
	}
}
