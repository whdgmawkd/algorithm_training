#include <stdio.h>
#include <string.h>
char op[5][10];
char num[11][10] = { "zero","one","two","three","four","five","six","seven","eight","nine","ten" };
int chk[11];
int n;
void parser() {
	int op1 = 100, op2 = 100;
	int rst;
	for (int a = 0;a < 11;a++) {
		chk[a] = 0;
	}
	if (strcmp(op[0], "zero") == 0)
		op1 = 0;
	else if (strcmp(op[0], "one") == 0)
		op1 = 1;
	else if (strcmp(op[0], "two") == 0)
		op1 = 2;
	else if (strcmp(op[0], "three") == 0)
		op1 = 3;
	else if (strcmp(op[0], "four") == 0)
		op1 = 4;
	else if (strcmp(op[0], "five") == 0)
		op1 = 5;
	else if (strcmp(op[0], "six") == 0)
		op1 = 6;
	else if (strcmp(op[0], "seven") == 0)
		op1 = 7;
	else if (strcmp(op[0], "eight") == 0)
		op1 = 8;
	else if (strcmp(op[0], "nine") == 0)
		op1 = 9;
	else if (strcmp(op[0], "ten") == 0)
		op1 = 10;
	if (strcmp(op[2], "zero") == 0)
		op2 = 0;
	else if (strcmp(op[2], "one") == 0)
		op2 = 1;
	else if (strcmp(op[2], "two") == 0)
		op2 = 2;
	else if (strcmp(op[2], "three") == 0)
		op2 = 3;
	else if (strcmp(op[2], "four") == 0)
		op2 = 4;
	else if (strcmp(op[2], "five") == 0)
		op2 = 5;
	else if (strcmp(op[2], "six") == 0)
		op2 = 6;
	else if (strcmp(op[2], "seven") == 0)
		op2 = 7;
	else if (strcmp(op[2], "eight") == 0)
		op2 = 8;
	else if (strcmp(op[2], "nine") == 0)
		op2 = 9;
	else if (strcmp(op[2], "ten") == 0)
		op2 = 10;
	if (op[1][0] == '+')
		rst = op1 + op2;
	else if (op[1][0] == '-')
		rst = op1 - op2;
	else if (op[1][0] == '*')
		rst = op1 * op2;
	if (0 > rst || rst > 10) {
		printf("No\n");
		return;
	}
	else {
		if (strlen(op[4]) != strlen(num[rst])) {
			printf("No\n");
			return;
		}
		int len = strlen(op[4]);
		for (int a = 0;a < len;a++) {
			for (int b = 0;b < strlen(num[rst]);b++) {
				if (op[4][a] == num[rst][b]&&chk[b]!=1) {
					chk[b] = 1;
					op[4][a] = 0;
					break;
				}
			}
		}
		int tmp = 0;
		for (int a = 0;a < len;a++) {
			tmp += op[4][a];
		}
		if (tmp > 0) {
			printf("No\n");
			return;
		}
		printf("Yes\n");
	}
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s %s %s %s %s", &op[0],10, &op[1],10, &op[2],10, &op[3],10, &op[4],10,10,10,10,10);
		parser();
	}
}