#define __CASE21_FAILED_TIMEOUT__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

char str[1000002];
char revstr[100002];
int rst;
void solve();

int main(void) {
	scanf_s("%s", str, 100000);
	solve();
	printf("%d", rst);
	return 0;
}

void solve() {
	int coll = 0;
	int len = strlen(str);
	strcpy_s(&revstr[0], 100000,&str[0]);
	std::reverse(&revstr[0], &revstr[len]);
	for (int a = 0;a <= len;a++) { // change start index
		for (int b = 1;b <= len - a;b++) { // change character lenth
			for (int c = 0;c < b;c++) { // loop each lenth
				printf("%d %d %c %c\n", a+c,len-(a+c)-1,str[a + c], str[(a+b)-c-1]);
				if(str[a+c]!=str[(a+b)-c-1]){
				//if (str[a + c] != revstr[len - (a -b+1) - 1]) {
					printf("break!\n");
					coll = 1;
					break;
				}
			}
			if (coll != 1)
				rst++;
			coll = 0;
			printf("\n");
		}
		printf("\n");
	}
}
