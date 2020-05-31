#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
	_node* prev;
	int Data;
	_node* next;
}Node;
typedef struct _list {
	Node* front;
	Node* rear;
}List;
int countList(List* lp);
void initList(List* lp) {
	lp->front = NULL;
	lp->rear = NULL;
}
bool isEmpty(List *lp) {
	if (lp->front == NULL) {
		return true;
	}
	return false;
}
// Add Node after rear
void addList(List* lp, int d) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = d;
	newNode->prev = NULL;
	newNode->next = NULL;
	if (isEmpty(lp)) {
		lp->front = newNode;
		lp->rear = newNode;
	}
	else {
		newNode->prev = lp->rear;
		lp->rear->next = newNode;
		lp->rear = newNode;
	}
}
// Delete np Node
int delList(List* lp, Node* np) {
	Node* delNode = np;
	int retData = np->Data;
	if (np == lp->front) {
		lp->front = lp->front->next;
		lp->front->prev = NULL;
	}
	else if (np == lp->rear) {
		lp->rear = lp->rear->prev;
		lp->rear->next = NULL;
	}
	else {
		np->prev->next = delNode->next;
		np->next->prev = delNode->prev;
	}
	free(delNode);
	return retData;
}
int countList(List* lp) {
	int count = 0;
	Node* pos = lp->front;
	if (isEmpty(lp)) {
		return -1;
	}
	while (pos != NULL) {
		count++;
		pos = pos->next;
	}
	return count;
}
Node* getNextNode(List* lp, Node* np) {
	if (np->next == NULL)
		return lp->front;
	return np->next;
}
void printList(List *lp) {
	Node* cur = lp->front;
	while (cur != NULL) {
		printf("%d ", cur->Data);
		cur = cur->next;
	}
	printf("\n");
}
int n, k, c;
int main(void) {
	scanf_s("%d", &c);
	for (int a = 0;a < c;a++) {
		List list;
		initList(&list);
		scanf_s("%d %d", &n, &k);
		for (int b = 1;b <= n;b++) {
			addList(&list, b);
		}
		Node* target = list.front;
		Node* next = getNextNode(&list, target);
		while (countList(&list) > 2) {
			delList(&list, target);
			for (int b = 1;b <= k;b++) {
				target = next;
				next = getNextNode(&list, target);
			}
		}
		printList(&list);
	}
}