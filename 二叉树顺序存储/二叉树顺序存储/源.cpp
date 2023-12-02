#include "标头.h"

//堆的创建
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

	// 建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->a, php->size, i);
	}
}
//堆的销毁
void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}
//交换两个元素
void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType x = *p1;
	*p1 = *p2;
	*p2 = x;
}

//向上调整算法：该位置之前的所有数据已经是一个堆了
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
//堆的插入
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

// 向下调整算法：左右子树都是大堆/小堆
void AdjustDown(HPDataType* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出左右孩子中大的那一个
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
//堆的弹出
void HeapPop(HP* php)
{
	assert(php);
	assert(!HeapEmpty(php));

	// 删除数据
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	AdjustDown(php->a, php->size, 0);
}
//返回堆顶数据
HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}
//判断堆是否为空
bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
//堆中元素个数
int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

int main()
{
	return 0;
}