#include "BiTree.h"


//初始化树的函数
void CreateBiTree(BiTree* T) {
	// 为根节点申请内存，并赋值1
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = 1;
	// 为根节点的左右子节点申请内存
	(*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	// 左子节点
	// 为左子节点赋值2，并为左子节点的左右子节点申请内存
	(*T)->lchild->data = 2;
	(*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	// 左子节点的左子节点
	// 赋值4，并为其左右子节点赋值NULL
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;

	// 左子节点的右子节点
	// 赋值5，并为其左右子节点赋值NULL
	(*T)->lchild->rchild->data = 5;
	(*T)->lchild->rchild->lchild = NULL;
	(*T)->lchild->rchild->rchild = NULL;

	// 右子节点
	// 赋值3，并为其左右子节点申请内存
	(*T)->rchild->data = 3;
	(*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	// 右子节点的左子节点
	// 赋值6，并为其左右子节点赋值NULL
	(*T)->rchild->lchild->data = 6;
	(*T)->rchild->lchild->lchild = NULL;
	(*T)->rchild->lchild->rchild = NULL;

	// 右子节点的右子节点
	// 赋值7，并为其左右子节点赋值NULL
	(*T)->rchild->rchild->data = 7;
	(*T)->rchild->rchild->lchild = NULL;
	(*T)->rchild->rchild->rchild = NULL;
}


//先序遍历
void PreOrderTraverse(BiTree T) {
	if (T) {
		printf("%d ", T->data); //操作结点数据
		PreOrderTraverse(T->lchild);//访问该结点的左孩子
		PreOrderTraverse(T->rchild);//访问该结点的右孩子
	}
	//如果结点为空，返回上一层
	return;
}
