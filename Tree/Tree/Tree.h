#ifndef _TREE_H_
#define _TREE_H_


#include <stdio.h>
#include <windows.h>
#define MAX 100

typedef struct BiNode{
	char data;
	struct BiNode *lchild, *rchild;
}BiNode,*BiTree;

typedef struct stack{
	BiTree data[MAX];
	int tag[MAX];
	int top;
}seq;

void pre(BiTree t);
void  mid(BiTree t);
void post(BiTree t);
BiTree pop(seq *s);
void push(seq *s, BiTree t);
void PreTree(BiTree t);
void InTree(BiTree t);
void PostTree(BiTree t);
void GreatTree(BiTree t);
void TierTree(BiTree t);



#endif