#pragma once
#ifndef BiTree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TElemType int

typedef struct BiTNode {
	TElemType data;//数据域
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;

// 初始化二叉树
void CreateBiTree(BiTree* T);
// 先序遍历
void PreOrderTraverse(BiTree T);
// 中序遍历

// 后序遍历



#endif // !BiTree
