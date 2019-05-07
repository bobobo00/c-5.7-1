#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"
int main(){
	BiTree t=NULL;
	GreatTree(&t);
	pre(t);
	printf("\n");
	mid(t);
	printf("\n");
	post(t);
	/*TierTree(t);
	printf("\n");
	PreTree(t);
	printf("\n");
	InTree(t);
	printf("\n");
	PostTree(t);
	printf("\n");*/
	system("pause");
	return 0;
}