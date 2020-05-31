#include <stdio.h>
#include <string.h>
int n;
double num;
char str[4];
void print(void) {
	if (strcmp(str, "kg") == 0)
		printf("%.4lf lb\n", num * 2.2046);
	else if (strcmp(str, "lb") == 0)
		printf("%.4lf kg\n", num * 0.4536);
	else if (strcmp(str, "l") == 0)
		printf("%.4lf g\n", num * 0.2642);
	else if (strcmp(str, "g") == 0)
		printf("%.4lf l\n", num * 3.7854);
}
int main(void) {
	scanf_s("%d", &n);
	for (int a = 1;a <= n;a++) {
		scanf_s("%lf %s", &num, str, 3);
		printf("%d ", a);
		print();
	}
}