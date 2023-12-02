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
//堆的创建
void HeapInitArray(HP* php, int* a, int n);
//堆的销毁
void HeapDestroy(HP* php);
//堆的插入
void HeapPush(HP* php, HPDataType x);
//弹出堆顶数据
void HeapPop(HP* php);
//返回堆顶数据
HPDataType HeapTop(HP* php);
//判断堆是否为空
bool HeapEmpty(HP* php);
//堆数据的个数
int HeapSize(HP* php);
//向上调整算法
void AdjustUp(HPDataType* a, int child);
//向下调整算法
void AdjustDown(HPDataType* a, int n, int parent);
