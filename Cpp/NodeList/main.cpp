#include"Node.h"
int main(void) {
	Node* HEAD=NULL;
	HEAD=initNode();

	insert(HEAD, 0, 10);
	pushBack(HEAD, 20);
	pushBack(HEAD, 30);
	pushBack(HEAD, 40);
	pushBack(HEAD, 50);

	erase(HEAD, 1);

	int found;
	find(HEAD, 30, &found);
	outputAll(HEAD);
	printf("position:%d", found);
}