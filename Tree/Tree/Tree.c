#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"
//先序遍历
void PreTree(BiTree t){
	if (t == NULL)
		return;
	printf("%c", t->data);
	PreTree(t->lchild);
	PreTree(t->rchild);
}
//中序遍历
void InTree(BiTree t){
	if (t == NULL)
		return;
	InTree(t->lchild);
	printf("%c", t->data);
	InTree(t->rchild);
}
//后序遍历
void PostTree(BiTree t){
	if (t == NULL)
		return;
	PostTree(t->lchild);
	PostTree(t->rchild);
	printf("%c", t->data);
}
//层次遍历
void TierTree(BiTree t){
	BiTree b;
	BiTree c[MAX];
	int front, rear;
	front = rear = -1;
	rear++;
	c[rear] = t;
	while (front != rear){
		front = (front + 1) % MAX;
		b = c[front];
		printf("%c", b->data);
		if (b->lchild != NULL){
			rear = (rear + 1) % MAX;
			c[rear] = b->lchild;
		}
		if (b->rchild != NULL){
			rear = (rear + 1) % MAX;
			c[rear] = b->rchild;
		}
	}
}
//先序构建二叉树
void GreatTree(BiTree *t){
	char c = '0';
	scanf("%c", &c);
	if (c == '#'){
		*t = NULL;
	}
	else{
		*t = (BiTree)malloc(sizeof(BiNode));
		if (!*t){
			exit(1);
		}
		(*t)->data = c;
		GreatTree(&((*t)->lchild));
		GreatTree(&((*t)->rchild));
	}
}
void push(seq *s, BiTree t){
	s->data[s->top] = t;
	s->top++;
}
BiTree pop(seq *s){
	if (s->top != 0){
		s->top--;
		return s->data[s->top];
	}
	else{
		return NULL;
	}
}
//迭代先序遍历二叉树
void pre(BiTree t){
	seq s;
	s.top = 0;
	while (t || (s.top != 0)){
		if (t){
			printf("%c", t->data);
			push(&s, t);
			t = t->lchild;
		}
		else{
			t=pop(&s);
			t = t->rchild;
		}
	}
}
//迭代中序遍历二叉树
void  mid(BiTree t)
{
	seq s;
	s.top = 0;
	while (t || (s.top!= 0))
	{
		if (t)
		{
			push(&s, t);//入栈 
			t = t->lchild;//指向左孩子 
		}
		else
		{
			t = pop(&s);//头结点出栈
			printf("%c", t->data);//打印头结点 
			t = t->rchild; //指向右孩子 
		}
	}
}
//迭代后序遍历二叉树
void post(BiTree t)
{
	seq s;
	s.top = 0;
	while (t||(s.top != 0))
	{
		if (t)
		{
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top++;
			t = t->lchild;
		}
		else if (s.tag[s.top - 1] == 1)
		{
			s.top--;
			t = s.data[s.top];
			printf("%c", t->data);
			t = NULL;
		}
		else
		{
			t = s.data[s.top - 1];
			s.tag[s.top - 1] = 0;
			t = t->rchild;
		}
	}
}


