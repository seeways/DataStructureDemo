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
		printf("%d ", T->data); //访问根节点
		PreOrderTraverse(T->lchild);//访问该结点的左孩子
		PreOrderTraverse(T->rchild);//访问该结点的右孩子
	}
	//如果结点为空，返回上一层
	return;
}

//中序遍历
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild);//遍历左孩子
		printf("%d ", T->data);//访问根节点
		INOrderTraverse(T->rchild);//遍历右孩子
	}
	//如果结点为空，返回上一层
	return;
}

//后序遍历
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//遍历左孩子
		PostOrderTraverse(T->rchild);//遍历右孩子
		printf("%d ", T->data);//访问根节点
	}
	//如果结点为空，返回上一层
	return;
}




// 层次遍历
void HierarchicalTraverse(BiTree node) {
	//初始化队头和队尾指针开始时都为0
	int front = 0, rear = 0;
	BiTNode* p;
	//采用顺序队列，初始化创建队列数组
	BiTree a[20];
	//根结点入队
	a[rear++] = node;
	//当队头和队尾相等时，表示队列为空
	while (front < rear) {
		//队头结点出队
		p = a[front++];
		printf("%d ", p->data);
		//将队头结点的左右孩子依次入队
		if (p->lchild != NULL) {
			a[rear++] = p->lchild;
		}
		if (p->rchild != NULL) {
			a[rear++] = p->rchild;
		}
	}
}