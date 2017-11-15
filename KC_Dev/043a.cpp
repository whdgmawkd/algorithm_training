#define __CASE10_FAILED_TIMEOUT__
#include <stdio.h>

double score[300005];
int scoreCnt;
int queryCnt;

typedef struct _queryOp {
	int cmd;
	int user;
	double score;
}QueryOp;
QueryOp queryOp[100000];

void getRank(int);
void updateScore(int, double);

int main(void) {
	scanf_s("%d", &scoreCnt);
	for (int a = 0;a < scoreCnt;a++) {
		scanf_s("%lf", &score[a]);
	}
	scanf_s("%d", &queryCnt);
	for (int a = 0;a < queryCnt;a++) {
		scanf_s("%d %d", &queryOp[a].cmd, &queryOp[a].user);
		if (queryOp[a].cmd == 2) {
			scanf_s("%lf", &queryOp[a].score);
		}
	}
	for (int a = 0;a < queryCnt;a++) {
		if (queryOp[a].cmd == 1)
			getRank(queryOp[a].user);
		else
			updateScore(queryOp[a].user, queryOp[a].score);
	}
	return 0;
}

void getRank(int index) {
	int rank = 1;
	for (int a = 0;a < scoreCnt;a++) {
		if (index-1 == a)
			continue;
		if (score[a] > score[index-1])
			rank++;
	}
	printf("%d\n", rank);
}

void updateScore(int index, double updateVal) {
	score[index-1] = updateVal;
}