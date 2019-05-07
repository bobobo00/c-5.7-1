#define _CRT_SECURE_NO_WARNINGS 1
#include "Tree.h"
//�������
void PreTree(BiTree t){
	if (t == NULL)
		return;
	printf("%c", t->data);
	PreTree(t->lchild);
	PreTree(t->rchild);
}
//�������
void InTree(BiTree t){
	if (t == NULL)
		return;
	InTree(t->lchild);
	printf("%c", t->data);
	InTree(t->rchild);
}
//�������
void PostTree(BiTree t){
	if (t == NULL)
		return;
	PostTree(t->lchild);
	PostTree(t->rchild);
	printf("%c", t->data);
}
//��α���
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
//���򹹽�������
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
//�����������������
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
//�����������������
void  mid(BiTree t)
{
	seq s;
	s.top = 0;
	while (t || (s.top!= 0))
	{
		if (t)
		{
			push(&s, t);//��ջ 
			t = t->lchild;//ָ������ 
		}
		else
		{
			t = pop(&s);//ͷ����ջ
			printf("%c", t->data);//��ӡͷ��� 
			t = t->rchild; //ָ���Һ��� 
		}
	}
}
//�����������������
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


