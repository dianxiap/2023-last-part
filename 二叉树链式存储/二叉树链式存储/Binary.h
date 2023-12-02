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

//手动创建一颗二叉树
BTNode* BuyNode(BTDataType x);
BTNode* CreatTree();
//前序遍历
void PreOrder(BTNode* root);
//中序遍历
void InOrder(BTNode* root);
//后序遍历
void PostOrder(BTNode* root);
//层序遍历
void LevelOrder(BTNode* root);
//二叉树节点的个数
int TreeSize(BTNode* root);
//二叉树的深度
int TreeHeight(BTNode* root);
//二叉树第k层节点的个数
int TreeKLevel(BTNode* root, int k);
//查找二叉树值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x);
// 二叉树销毁
void TreeDestory(BTNode* root);
