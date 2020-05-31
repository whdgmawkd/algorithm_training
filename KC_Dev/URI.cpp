#include <stdio.h>
#include <string.h>
char str[81];
int n;
void print(void) {
	int len = strlen(str);
	for (int a = 0;a < len;a++) {
		if (str[a] == '%') {
			if (str[a + 1] == '2') {
				switch (str[a + 2]) {
				case '0':
					printf(" ");
					break;
				case '1':
					printf("!");
					break;
				case '2':
					printf("\"");
					break;
				case '3':
					printf("#");
					break;
				case '4':
					printf("$");
					break;
				case '5':
					printf("%%");
					break;
				case '6':
					printf("&");
					break;
				case '7':
					printf("\'");
					break;
				case '8':
					printf("(");
					break;
				case '9':
					printf(")");
					break;
				case 'a':
					printf("*");
					break;
				case 'b':
					printf("+");
					break;
				case 'c':
					printf(",");
					break;
				case 'd':
					printf("-");
					break;
				case 'e':
					printf(".");
					break;
				case 'f':
					printf("/");
					break;
				default:
					printf("%c%c%c", str[a], str[a + 1],str[a + 2]);
					break;
				}
			}
			a += 2;
		}
		else
			printf("%c", str[a]);
	}
	printf("\n");
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 0;a < n;a++) {
		scanf_s("%s", str, 80);
		print();
	}
}