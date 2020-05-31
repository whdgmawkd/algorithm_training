#include <stdio.h>
#include <string.h>
char g[200001];
char f[200001];
int t;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%s", g, 200000);
		scanf_s("%s", f, 200000);
		int glen = strlen(g);
		int flen = strlen(f);
		int count = 0;
		for (int b = 0;b <= flen-glen;b++) { 
			int limit = (flen - b) < glen ? flen - b : glen;
			for (int c = 0;c < limit;c++) {
				printf("%c %c %d %d\n", g[c], f[b + c], b, c);
				if (g[c] == f[b + c]) {
					break;
				}
			}
			count++;
		}
		printf("%d\n", count);
	}
}