#include <stdio.h>
int max=0x80000000, min=0x7fffffff, cnt;
int n, m, tmp;
int countPrime(int s, int e);
int isPrime(int num);
int main(void) {
	scanf_s("%d %d", &m, &n);
	if (m > n) {
		tmp = m;
		m = n;
		n = tmp;
	}
	cnt = countPrime(m, n);
	printf("%d\n%d\n", cnt, min + max);
	return 0;
}
int countPrime(int s, int e) {
	for (int a = s;a <= e;a++)
		if (isPrime(a))
			cnt++;
	return cnt;
}
int isPrime(int num) {
	for (int a = 2;a*a <= num;a++)
		if (num%a == 0)
			return 0;
	if (max < num)
		max = num;
	if (min > num)
		min = num;
	return 1;
}