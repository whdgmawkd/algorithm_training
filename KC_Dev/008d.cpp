#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char stack[51];
int stackIndex = 0;
char str[51];
char postFixExp[51];

int getOpPrec(char op) {
	if (op == '(')
		return 0;
	else if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else
		return -1;
}

int selOpPrec(char op1, char op2) {
	int op1Prec = getOpPrec(op1);
	int op2Prec = getOpPrec(op2);
	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

int infixToPostfix() {
	int infixLen = strlen(str);
	char token;
	char popOp;
	int index = 0;
	for (int a = 0;a < infixLen;a++) {
		token = str[a];
		if (isalnum(token))
			postFixExp[index++] = token;
		else {
			switch (token) {
			case '(':
				stack[stackIndex++]=token;
				break;
			case ')':
				while (1) {
					popOp = stack[--stackIndex];
					if (popOp == '(')
						break;
					postFixExp[index++] = popOp;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (stackIndex > -1 && selOpPrec(stack[stackIndex-1], token) >= 0) {
					postFixExp[index++] = stack[--stackIndex];
				}
				stack[stackIndex++] = token;
				break;
			}
		}
	}
	while (stackIndex > -1) {
		postFixExp[index++] = stack[--stackIndex];
	}
	return 0;
}

int main(void) {
	scanf_s("%s", str, 50);
	infixToPostfix();
	printf("%s\n", postFixExp);
	return 0;
}