#pragma once
#ifndef BiTree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TElemType int

typedef struct BiTNode {
	TElemType data;//������
	struct BiTNode* lchild, * rchild;//���Һ���ָ��
}BiTNode, * BiTree;

// ��ʼ��������
void CreateBiTree(BiTree* T);
// �������
void PreOrderTraverse(BiTree T);
// �������

// �������



#endif // !BiTree
