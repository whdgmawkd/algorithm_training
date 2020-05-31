#define __RETIRE__
#define __REQUIRE_BIGINT__
#include <stdio.h>
#define Data unsigned long long
Data w, h, s;
int main(void) {
	scanf_s("%lld %lld", &w, &h);
	s = (w*h) % 1000000000000000000;
	printf("%lld", s);
}