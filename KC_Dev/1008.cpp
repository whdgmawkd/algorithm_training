#include <stdio.h>
double a, b;
int main(void) {
	scanf_s("%lf %lf", &a, &b);
	printf("%.10lf\n", a / b);
}