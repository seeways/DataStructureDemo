#pragma once
#ifndef BiTree

#include <stdio.h>
#include <stdlib.h>
#define TElemType int

typedef struct BiTNode {
	TElemType data;//������
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;

void CreateBiTree(BiTree* T);


#endif // !BiTree
