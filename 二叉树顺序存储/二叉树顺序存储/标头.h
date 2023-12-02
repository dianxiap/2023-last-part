#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//�ѵĴ���
void HeapInitArray(HP* php, int* a, int n);
//�ѵ�����
void HeapDestroy(HP* php);
//�ѵĲ���
void HeapPush(HP* php, HPDataType x);
//�����Ѷ�����
void HeapPop(HP* php);
//���ضѶ�����
HPDataType HeapTop(HP* php);
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php);
//�����ݵĸ���
int HeapSize(HP* php);
//���ϵ����㷨
void AdjustUp(HPDataType* a, int child);
//���µ����㷨
void AdjustDown(HPDataType* a, int n, int parent);
