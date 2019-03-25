#include "SeqList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//����
void SeqListInit(SeqList *pSeqList) {
		//���������׵�ַ����Ϊ��
	assert(pSeqList != NULL);
		//���ٿռ�
	pSeqList->capacity = 10;
	pSeqList->array = ((int*)malloc(sizeof(int)*pSeqList->capacity));
	pSeqList->size = 0;
}
//����
void SeqListDestory(SeqList* pSeqList) {
	free(pSeqList);
	assert(pSeqList);
}
//���������������������������
 static void SeqListCheckCapacity(SeqList* pSeqList) {
	 if (pSeqList->size < pSeqList->capacity) {
		 return;
	 }
	 //�����Ĵ�СС������   �����·���
	 int Newcapacity = pSeqList->capacity * 2;//����һ��Ϊ2��
	 int * Newarray = (int*)malloc(sizeof(int)*Newcapacity);
	 assert(Newarray);
	 for (int i = 0; i < pSeqList->size; i++) {
		 Newarray[i] = pSeqList->array[i];
		}
	 //��ԭ�����ݸ��Ƶ��±���

	 free(pSeqList->array);//�ſ�ԭ�����ڴ�
	 pSeqList->array = Newarray;//ָ���������ڴ�
	 pSeqList->capacity = Newcapacity;//����


}
//��ɾ���

//��
//ͷ��
void SeqListPushFront(SeqList* pSeqList, int value) {
	SeqListCheckCapacity(pSeqList);
	for (int i = pSeqList->size; i >= 1; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}
//β��
void SeqListPushBack(SeqList* pSeqList, int value) {
	SeqListCheckCapacity(pSeqList);
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//�������λ��pos�Ͳ���ֵvalue���в���
void SeqListInsert(SeqList* pSeqList, int pos, int value) {
	SeqListCheckCapacity(pSeqList);
	for (int i = pSeqList->size; i >= pos; i--) {
		pSeqList->array[i] = pSeqList->array[i - 1];
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
//ɾ
//ͷɾ
void SeqListPopFront(SeqList* pSeqList) {
	assert(pSeqList->size > 0);
	for (int i = 0; i <= pSeqList->size - 1; i++) {
		pSeqList->array[i] = pSeqList->array[i + 1];
	}
	pSeqList->size--;
}
// βɾ
void SeqListPopBack(SeqList *pSeqList) {
	assert(pSeqList->size > 0);
	pSeqList->size--;
}
// �����±� pos ��ɾ��
void SeqListErase(SeqList *pSeqList, int pos) {
	assert(pSeqList->size > 0);
	for (int i = pos; i <= pSeqList->size - 1; i++) {
		pSeqList->array[i] = pSeqList->array[i + 1];
	}
	pSeqList->size--;
}
//��
int SeqListSearch(const SeqList *pSeqList, int value) {
	for (int i = 0; i < pSeqList->size; i++){
		if (pSeqList->array[i] == value) {
			return i;
		}
	}
	return -1;
}
// �޸� pos �±����ڵ�ֵΪ value
void SeqListModify(SeqList *pSeqList, int pos, int value) {
	assert(pos >= 0 && pos <= pSeqList->size);
	pSeqList->array[pos] = value;
}
// ɾ�������ĵ�һ�� value
void SeqListRemove(SeqList *pSeqList, int value) {
	int pos = SeqListFind(pSeqList, value);
	if (pos != -1) {
		SeqListErase(pSeqList, pos);
	}
}
// ɾ������������ value
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
//SeqListRemoveAll�ĵݹ���
void SeqListRemoveAll1(SeqList *ps, int value, int pos) {
	//��pos����ʼѰ��value��ɾ��

}