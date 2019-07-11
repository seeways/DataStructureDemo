#pragma once
#ifndef BiTree

#include <stdio.h>
#include <stdlib.h>
#define TElemType int

typedef struct BiTNode {
	TElemType data;//数据域
	struct BiTNode* lchild, * rchild;//左右孩子指针
}BiTNode, * BiTree;

void CreateBiTree(BiTree* T);


#endif // !BiTree
