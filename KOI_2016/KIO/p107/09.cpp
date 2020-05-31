#include <stdio.h>
#include <thread>

// digit of solved value.
int digit;
int cnt;

void f(int, int);
bool isPrime(int);

int main(void) {
	scanf_s("%d", &digit);
	std::thread t1(&f, 2, 1);
	std::thread t2(&f, 3, 1);
	std::thread t3(&f, 5, 1);
	std::thread t4(&f, 7, 1);
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	printf("%d\n", cnt);
}

bool isPrime(int num) {
	for (int i = 2;i*i <= num;i++) {
		if (num%i == 0) {
			return 0;
		}
	}
	return 1;
}

void f(int num, int len) {
	if (len == digit) {
		if (isPrime(num)) {
			cnt++;
			printf("%d\n", num);
		}
		return;
	}
	else {
		if (isPrime(num)) {
			f(num * 10 + 1, len + 1);
			f(num * 10 + 3, len + 1);
			f(num * 10 + 7, len + 1);
			f(num * 10 + 9, len + 1);
		}
	}
}