#include "BiTree.h"



void CreateBiTree(BiTree* T) {
	// Ϊ���ڵ������ڴ棬����ֵ1
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = 1;
	// Ϊ���ӽڵ������ڴ棬����ֵ2
	(*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->data = 2;
	// Ϊ���ӽڵ������ڴ棬����ֵ3
	(*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->data = 3;
	// ���ӽڵ�������ӽڵ���NULL
	(*T)->rchild->lchild = NULL;
	(*T)->rchild->rchild = NULL;
	// ���ӽڵ�����ӽڵ������ڴ棬����ֵ4�����ӽڵ���NULL
	(*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->rchild = NULL;
	// ���ӽڵ�����ӽڵ�������ӽڵ���NULL
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;
	// ���ˣ�һ�����ʹ�������
}