#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// ����Ĳ�������Ľṹ�壬����������һ�����Ľṹ��
typedef struct Node {
	int value;
	struct  Node *next;
} Node;

//����һ��ͷ���Ϊ�ṹ��SList
typedef struct SList {
	Node *head;	// ���������ͷ���
}	SList;

//��ʼ������
void SListInit(SList *s) {//���������ͷ�������Ϊ��
	assert(s != NULL);
	s->head == NULL;
}

//����
//ͷ��
void SListPushFront(SList *s, int value) {//���������ͷ�����Ҫ�����ֵ
	Node *node = (Node *)malloc(sizeof(Node));//����һ���½ڵ�
	node->value = value;		//��value����������ֵ
	node->next = s->head;		//���ڵ��β����ԭ��ͷ�Ľ������
	s->head = node;				//��ͷ��������Ľ������
}//O(1)

//β��
void SListPushBack(SList *s, int value) {//���������ͷ�����Ҫ�����ֵ
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;		//��value����������ֵ
	node->next = NULL;			//������β����NULL����
	if (s->head == NULL) {		//�ж�Ҫ����ı��Ƿ�Ϊ�գ���Ϊ�գ�ֱ������
		s->head = node;
		return;
	}
	Node *cur = s->head;		//����һ��������������β����һ��α���
	while (cur->next != NULL)	//��cur����һ�����Ϊ��֤�����ѵ�������β��
	{
		cur = cur->next;
	}
	cur->next = node;			//cur->next�޸ĵ�������β������->next
}//��������Ϊn��whileѭ��n�� sʱ�临�Ӷ�ΪO(n),���޽����ΪO(1)

//ɾ��
//ͷɾ
void SListPopFront(SList *s) {	//����Ҫ����������
	assert(s != NULL);			//����û������
	assert(s->head != NULL);	//����û�н��
	//s->head = s->head->next;	ֱ�ӽ�ͷ����������ڶ����ڵ㣬����Ҫ�ͷ��׽ڵ�Ŀռ�
	Node *next = s->head->next;	//����һ��next������ŵڶ����ڵ�ĵ�ַ
	free(s->head);				//�ͷ��׽ڵ�ռ�
	s->head = next;				//���ղŴ洢�ĵڶ����ڵ��ַ�����׽ڵ�
}
//βɾ
void SListPopBack(SList *s) {	//����Ҫ����������
	assert(s != NULL);			//����û������
	assert(s->head != NULL);	//����û�н��
	if (s->head->next == NULL) {//��ֻ��һ���ڵ� ֱ�����׽ڵ�ָ���
		free(s->head);
		s->head = NULL;
		return;
	}
	Node *cur = s->head;		//����һ�����������������ڶ���һ��α���
	while (cur->next->next != NULL)	//��cur����һ�����Ϊ��֤�����ѵ����������ڶ����ڵ�
	//for (cur = s->first; cur->next->next != NULL; cur = cur->next)����һ��forѭ����Ч
	{
		cur = cur->next;
	}
	free(cur->next);			//�ͷ����һ���ڵ�Ŀռ�
	cur->next = NULL;			//����ڶ����ڵ�ָ���
}

//��ת����
struct Node* reverseList(struct Node* head) {//����һ���ı�ͷ
	//��ԭ����ͷɾ��������ͷ��
	struct Node *newhead = NULL;	//��󷵻صı�ͷ
	struct Node *cur = head;		//��������������α�ڵ�
	while (cur!=NULL)
	{
		cur->next = newhead;
		newhead = cur;
		cur = cur->next;
	}
	return newhead;
}
//�������
Node * SListFind(SList *s, int v) {
	for (Node *cur = s->head; cur != NULL; cur = cur->next) {
		if (cur->value == v) {
			return cur;
		}
	}
}
//��pos�����ֵΪvalue�Ľ��
//������һ��Ҫ��pos���
void SListInsertAfter(SList *s, Node *pos,int v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//ɾ��pos�����һ���ڵ�
void SListEraseAfter(SList *s, Node *pos) {
	Node *node = pos->next;
	pos->next = pos->next->next;
	free(node);
}
//ɾ������
void SListDestroy(SList *s) {
	Node *node;
	for (Node *cur=s->head; cur != NULL; cur = node) {
		node = cur->next;
		free(cur);
	}
	s->head = NULL;
}
//ɾ��ֵΪv�Ľ��(ɾ������ֵΪv�Ľ��)
void SListRemove(SList *s, int v) {
//�������û�нڵ�
	if (s->head == NULL) {
		return;
	}
	Node *cur = s->head;
	while (cur != NULL) {
		if (cur->value == v) {
			Node *next = cur->next;
			free(cur);
			cur = next;
		}
		else {
			cur = cur->next;
		}
	}
	return;
}
//ֻɾ����һ��������ֵΪv�Ľ��
void SListRemove1(SList *s, int v) {
	//�������û�нڵ�
	if (s->head == NULL) {
		return;
	}
	Node *cur = s->head;
	while (cur != NULL) {
		if (cur->value == v) {
			Node *next = cur->next;
			free(cur);
			cur = next;
			return;
		}
		else {
			cur = cur->next;
		}
	}
	return;
}
//����ϲ�����
struct SList *Merge(struct SList *l1, struct SList *l2) {
	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}
	struct SList *s = NULL;
	struct Node *node = NULL;
	struct Node *n1 = l1->head;
	struct Node *n2 = l2->head;
	while (n1 != NULL && n2 != NULL) {
		if (n1->value <= n2->value) {
			if (node == NULL) {
				s->head = node = n1;
			}
			else {
				node->next = n1;
				node = n1;
			}
			n1 = n1->next;
		}
		else {
			if (node == NULL) {
				s->head = node = n2;
			}
			else {
				node->next = n2;
				node = n2;
			}
			n2 = n2->next;
		}
	}
	if (n1 == NULL) {
		node->next = n2;
	}
	else {
		node->next = n1;
	}
	return s;
}
//��ת��������ͷɾ��ͷ�彨��������
Node *Reverse(Node *head) {
	Node *s = NULL;
	Node *cur = head;
	while (cur != NULL) {
		Node *next = cur->next;
		cur->next = s;
		s = cur;
		cur = next;
	}
	return s;
}
//��vֵΪ�磬��С��v�ķ���ǰ��,����v�ķ��ں��棨����v��
Node *partition(Node *head, int v) {
	Node *small = NULL;
	Node *big = NULL;
	Node *small_last = NULL;
	Node *big_last;
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		if (cur->value < v) {
			if (small == NULL) {
				small = small_last = cur;
			}
			else {
				small_last->next = cur;
				small_last = cur;
			}
		}
		else {
			if (big == NULL) {
				big = big_last = cur;
			}
			else {
				big_last->next = cur;
				big_last = cur;
			}
		}
	}
	if (small_last != NULL) {
		small_last->next = big;
	}
	if (big_last != NULL) {
		big_last->next = NULL;
	}
	if (small == NULL) {
		return big;
	}
	else {
		return small;
	}
}