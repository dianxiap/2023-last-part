#include "��ͷ.h"

//�ѵĴ���
void HeapInitArray(HP* php, int* a, int n)
{
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}

	php->size = n;
	php->capacity = n;

	// ����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, php->size, i);
	}
}
//�ѵ�����
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//��������Ԫ��
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//���ϵ����㷨����λ��֮ǰ�����������Ѿ���һ������
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	//while (parent >= 0)
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
//�ѵĲ���
void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	if (php->size == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity *= 2;
	}

	php->a[php->size] = x;
	php->size++;

	AdjustUp(php->a, php->size - 1);
}

// ���µ����㷨�������������Ǵ��/С��
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// ѡ�����Һ����д����һ��
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//�ѵĵ���
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	// ɾ������
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}
//���ضѶ�����
HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}
//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
//����Ԫ�ظ���
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

int main()
{
	return 0;
}