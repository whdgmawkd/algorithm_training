#define __02D6_AND_02D7__
#include "lib.h"
void quickSort(int, int);
int main(void) {
	quickSort(0, Sizef() - 1);
	done();
	return 0;
}
void quickSort(int left, int right) {
	int l = left, r = right;
	double tmp;
	double pivot = (Getf(left) + Getf(right)) / 2;// arr[(left + right) / 2];
	while (l <= r) {
		while (Getf(l) < pivot)
			l++;
		while (Getf(r) > pivot)
			r--;
		if (l <= r) {
			tmp = Getf(l);
			Putf(Getf(r), l);
			Putf(tmp, r);
			l++;
			r--;
		}
	}
	if (left < r) quickSort(left, r);
	if (l < right) quickSort(l, right);
}