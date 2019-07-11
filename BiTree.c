#include "BiTree.h"



void CreateBiTree(BiTree* T) {
	// 为根节点申请内存，并赋值1
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = 1;
	// 为左子节点申请内存，并赋值2
	(*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->data = 2;
	// 为右子节点申请内存，并赋值3
	(*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->data = 3;
	// 右子节点的左右子节点置NULL
	(*T)->rchild->lchild = NULL;
	(*T)->rchild->rchild = NULL;
	// 左子节点的左子节点申请内存，并赋值4，右子节点置NULL
	(*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->rchild = NULL;
	// 左子节点的左子节点的左右子节点置NULL
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;
	// 至此，一个树就创建好了
}