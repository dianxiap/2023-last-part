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

//��ʼ��
void QueueInit(Queue* pq);
//����
void QueueDestroy(Queue* pq);
//��β����
void QueuePush(Queue* pq, QDatatype x);
//��ͷ����
void QueuePop(Queue* pq);
//����Ԫ�ظ���
int QueueSize(Queue* pq);
//�ж϶��Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);
//���ض�ͷԪ��
QDatatype QueueFront(Queue* pq);
//���ض�βԪ��
QDatatype QueueBack(Queue* pq);
