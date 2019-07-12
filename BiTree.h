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
void INOrderTraverse(BiTree T);
// �������
void PostOrderTraverse(BiTree T);
// ��α���
void HierarchicalTraverse(BiTree tree);


#endif // !BiTree
