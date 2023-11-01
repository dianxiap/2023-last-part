#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2)
{
    if (!L1 && !L2)
    {
        return NULL;
    }
    List L3 = (List*)malloc(sizeof(List));
    L3->Next = NULL;
    List p1 = L1;
    List p2 = L2;
    List p3 = L3;

    while (p1 && p2)
    {
        if (p1->Data < p2->Data)
        {
            p3->Next = p1;
            p1 = p1->Next;
        }
        else
        {
            p3->Next = p2;
            p2 = p2->Next;
        }
        p3 = p3->Next;
    }
    while (p1)
    {
        p3->Next = p1;
        p1 = p1->Next;
        p3 = p3->Next;
    }
    while (p2)
    {
        p3->Next = p2;
        p2 = p2->Next;
        p3 = p3->Next;
    }
    p1->Next = NULL;
    p2->Next = NULL;
    return L3;
    
}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */