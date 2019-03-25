#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//创建
void SeqListInit(SeqList *pSeqList) {
		//传进来的首地址不能为空
	assert(pSeqList != NULL);
		//开辟空间
	pSeqList->capacity = 10;
	pSeqList->array = ((int*)malloc(sizeof(int)*pSeqList->capacity));
	pSeqList->size = 0;
}
//销毁
void SeqListDestory(SeqList* pSeqList) {
	free(pSeqList);
	assert(pSeqList);
}
//检测表的容量，若容量不足则扩容
 static void SeqListCheckCapacity(SeqList* pSeqList) {
	 if (pSeqList->size < pSeqList->capacity) {
		 return;
	 }
	 //如果表的大小小于容量   则无事发生
	 int Newcapacity = pSeqList->capacity * 2;//扩容一般为2倍
	 int * Newarray = (int*)malloc(sizeof(int)*Newcapacity);
	 assert(Newarray);
	 for (int i = 0; i < pSeqList->size; i++) {
		 Newarray[i] = pSeqList->array[i];
		}
	 //将原表内容复制到新表中

	 free(pSeqList->array);//放开原数组内存
	 pSeqList->array = Newarray;//指向新数组内存
	 pSeqList->capacity = Newcapacity;//扩容


}
//增删查改

//增
//头增
void SeqListPushFront(SeqList* pSeqList, int value) {
	SeqListCheckCapacity(pSeqList);
	for (int i = pSeqList->size; i >= 1; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}
//尾增
void SeqListPushBack(SeqList* pSeqList, int value) {
	SeqListCheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//输入插入位置pos和插入值value进行插入
void SeqListInsert(SeqList* pSeqList, int pos, int value) {
	SeqListCheckCapacity(pSeqList);
	for (int i = pSeqList->size; i >= pos; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
//删
//头删
void SeqListPopFront(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	for (int i = 0; i <= pSeqList->size - 1; i++) {
		pSeqList->array[i] = pSeqList->array[i + 1];
	}
	pSeqList->size--;
}
// 尾删
void SeqListPopBack(SeqList *pSeqList) {
	assert(pSeqList->size > 0);
	pSeqList->size--;
}
// 根据下标 pos 做删除
void SeqListErase(SeqList *pSeqList, int pos) {
	assert(pSeqList->size > 0);
	for (int i = pos; i <= pSeqList->size - 1; i++) {
		pSeqList->array[i] = pSeqList->array[i + 1];
	}
	pSeqList->size--;
}
//查
int SeqListSearch(const SeqList *pSeqList, int value) {
	for (int i = 0; i < pSeqList->size; i++){
		if (pSeqList->array[i] == value) {
			return i;
		}
	}
	return -1;
}
// 修改 pos 下标所在的值为 value
void SeqListModify(SeqList *pSeqList, int pos, int value) {
	assert(pos >= 0 && pos <= pSeqList->size);
	pSeqList->array[pos] = value;
}
// 删除遇到的第一个 value
void SeqListRemove(SeqList *pSeqList, int value) {
	int pos = SeqListFind(pSeqList, value);
	if (pos != -1) {
		SeqListErase(pSeqList, pos);
	}
}
// 删除遇到的所有 value
void SeqListRemoveAll(SeqList *pSeqList, int value) {
	int j = 0;
	for (int i = 0; i <= pSeqList->size - 1; i++) {
		if (pSeqList->array[i] != value) {
			pSeqList->array[j] = pSeqList->array[i];
			j++;
		}
	}
	pSeqList->size = j;
}
//SeqListRemoveAll的递归解决
void SeqListRemoveAll1(SeqList *ps, int value, int pos) {
	//从pos处开始寻找value并删除

}