#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef char QDatatype;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDatatype data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);
//队尾插入
void QueuePush(Queue* pq, QDatatype x);
//队头弹出
void QueuePop(Queue* pq);
//对内元素个数
int QueueSize(Queue* pq);
//判断队是否为空
bool QueueEmpty(Queue* pq);
//返回队头元素
QDatatype QueueFront(Queue* pq);
//返回队尾元素
QDatatype QueueBack(Queue* pq);
