#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//�ֶ�����һ�Ŷ�����
BTNode* BuyNode(BTDataType x);
BTNode* CreatTree();
//ǰ�����
void PreOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);
//�������
void LevelOrder(BTNode* root);
//�������ڵ�ĸ���
int TreeSize(BTNode* root);
//�����������
int TreeHeight(BTNode* root);
//��������k��ڵ�ĸ���
int TreeKLevel(BTNode* root, int k);
//���Ҷ�����ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x);
// ����������
void TreeDestory(BTNode* root);
