#include <stdio.h>
#include <math.h>
int t;
int m, s, c;
double rM, rS, cosM, cosS, Sm, csS, csM, tS, tM, aM, aS, areaS, areaM, rst;
int main(void) {
	scanf_s("%d", &t);
	for (int a = 0;a < t;a++) {
		scanf_s("%d %d %d", &m, &s, &c);
		Sm = acos(-1.0)*pow(m, 2); // pi*m^2
		cosS = (double)(c*c + m*m - s*s) / (2 * m*c); // { c^2+m^2-s^2 } over { 2*m*c } --> lay of cosine. located on center of circle M
		cosM = (double)(c*c - m*m + s*s) / (2 * s*c); // { c^2+s^2-m^2 } over { 2*s*c } --> lay of cosine. located on center of circle S
		aS = acos(cosM) * 2; // cos^-1(cosM)*2 = arccos(cosM)*2 --> angle of circle sector S. located on center of circle S
		aM = acos(cosS) * 2; // cos^-1(cosS)*2 = arccos(cosS)*2 --> angle of circle sector M. located on center of circle M
		csM = 0.5*pow(m, 2)*aM; // circle sector area of M
		csS = 0.5*pow(s, 2)*aS; // circle sector area of S
		tM = 0.5*pow(m, 2)*sin(aM); // area of triangle M
		tS = 0.5*pow(s, 2)*sin(aS); // area of tirangle S
		areaS = csS - tS;
		areaM = csM - tM;
		rst = Sm - (areaS + areaM);
		printf("%.3lf\n", rst);
	}
}