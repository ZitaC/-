#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
// 定义的不是链表的结构体，而是链表中一个结点的结构体
typedef struct Node {
	int value;
	struct  Node *next;
} Node;

//定义一个头结点为结构体SList
typedef struct SList {
	Node *head;	// 单向链表的头结点
}	SList;

//初始化链表
void SListInit(SList *s) {//传入链表的头结点令它为空
	assert(s != NULL);
	s->head == NULL;
}

//插入
//头插
void SListPushFront(SList *s, int value) {//输入链表的头结点与要插入的值
	Node *node = (Node *)malloc(sizeof(Node));//定义一个新节点
	node->value = value;		//将value赋予插入结点的值
	node->next = s->head;		//将节点的尾部与原表头的结点连接
	s->head = node;				//将头结点与插入的结点连接
}//O(1)

//尾插
void SListPushBack(SList *s, int value) {//输入链表的头结点与要插入的值
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = value;		//将value赋予插入结点的值
	node->next = NULL;			//将结点的尾部与NULL连接
	if (s->head == NULL) {		//判断要插入的表是否为空，若为空，直接连接
		s->head = node;
		return;
	}
	Node *cur = s->head;		//定义一个用来遍历至表尾部的一个伪结点
	while (cur->next != NULL)	//若cur的下一个结点为空证明其已到达链表尾部
	{
		cur = cur->next;
	}
	cur->next = node;			//cur->next修改的是链表尾部结点的->next
}//若链表结点为n则while循环n次 s时间复杂度为O(n),若无结点则为O(1)

//删除
//头删
void SListPopFront(SList *s) {	//传入要操作的链表
	assert(s != NULL);			//不能没有链表
	assert(s->head != NULL);	//不能没有结点
	//s->head = s->head->next;	直接将头结点连接至第二个节点，但是要释放首节点的空间
	Node *next = s->head->next;	//定义一个next用来存放第二个节点的地址
	free(s->head);				//释放首节点空间
	s->head = next;				//将刚才存储的第二个节点地址赋予首节点
}
//尾删
void SListPopBack(SList *s) {	//传入要操作的链表
	assert(s != NULL);			//不能没有链表
	assert(s->head != NULL);	//不能没有结点
	if (s->head->next == NULL) {//若只有一个节点 直接让首节点指向空
		free(s->head);
		s->head = NULL;
		return;
	}
	Node *cur = s->head;		//定义一个用来遍历至表倒数第二的一个伪结点
	while (cur->next->next != NULL)	//若cur的下一个结点为空证明其已到达链表倒数第二个节点
	//for (cur = s->first; cur->next->next != NULL; cur = cur->next)与上一行for循环等效
	{
		cur = cur->next;
	}
	free(cur->next);			//释放最后一个节点的空间
	cur->next = NULL;			//令倒数第二个节点指向空
}

//反转链表
struct Node* reverseList(struct Node* head) {//返回一个的表头
	//将原链表头删，新链表头插
	struct Node *newhead = NULL;	//最后返回的表头
	struct Node *cur = head;		//用来遍历至最后的伪节点
	while (cur!=NULL)
	{
		cur->next = newhead;
		newhead = cur;
		cur = cur->next;
	}
	return newhead;
}
//链表查找
Node * SListFind(SList *s, int v) {
	for (Node *cur = s->head; cur != NULL; cur = cur->next) {
		if (cur->value == v) {
			return cur;
		}
	}
}
//在pos后插入值为value的结点
//链表中一定要有pos结点
void SListInsertAfter(SList *s, Node *pos,int v) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}
//删除pos后的下一个节点
void SListEraseAfter(SList *s, Node *pos) {
	Node *node = pos->next;
	pos->next = pos->next->next;
	free(node);
}
//删除链表
void SListDestroy(SList *s) {
	Node *node;
	for (Node *cur=s->head; cur != NULL; cur = node) {
		node = cur->next;
		free(cur);
	}
	s->head = NULL;
}
//删除值为v的结点(删除所有值为v的结点)
void SListRemove(SList *s, int v) {
//如果表里没有节点
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
//只删除第一个遇到的值为v的结点
void SListRemove1(SList *s, int v) {
	//如果表里没有节点
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
//按序合并链表
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
//反转链表（利用头删和头插建立新链表）
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
//以v值为界，将小于v的放在前面,大于v的放在后面（不含v）
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