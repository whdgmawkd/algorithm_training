#include <stdio.h>
int c;
unsigned int input;
unsigned int buf[4];
unsigned int output;
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		scanf_s("%d", &input);
		for (int b = 0;b < 4;b++) {
			buf[b] = input & 0xff;
			input = input >> 8;
		}
		for (int b = 0;b < 4;b++) {
			output = output << 8;
			output += buf[b];
		}
		printf("%u\n", output);
	}
}