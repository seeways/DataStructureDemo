#include "ThreadBinaryTree.h"


BiThrTree pre = NULL;

//采用前序初始化二叉树
//中序和后序只需改变赋值语句的位置即可
void CreateTree(BiThrTree* tree) {
	char data;
	scanf("%c", &data);
	if (data != '#') {
		if (!((*tree) = (BiThrNode*)malloc(sizeof(BiThrNode)))) {
			printf("申请结点空间失败");
			return;
		}
		else {
			(*tree)->data = data;//采用前序遍历方式初始化二叉树
			CreateTree(&((*tree)->lchild));//初始化左子树
			CreateTree(&((*tree)->rchild));//初始化右子树
		}
		printf("%c",(*tree)->data);
	}
	else {
		*tree = NULL;
	}

}

//中序对二叉树进行线索化
void InThreading(BiThrTree p) {
	//如果当前结点存在
	if (p) {
		InThreading(p->lchild);//递归当前结点的左子树，进行线索化
		//如果当前结点没有左孩子，左标志位设为1，左指针域指向上一结点pre
		if (!p->lchild) {
			p->Ltag = Thread;
			p->lchild = pre;
		}
		//如果pre 没有右孩子，右标志位设为1，右指针域指向当前结点。
		if (pre && !pre->rchild) {
			pre->Rtag = Thread;
			pre->rchild = p;
		}
		pre = p;//pre 指向当前结点
		InThreading(p->rchild);//递归右子树进行线索化
	}
}

//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p)
{
	while (p)
	{
		//一直找左孩子，最后一个为中序序列中排第一的
		while (p->Ltag == Link) {
			p = p->lchild;
			printf("%c ", p->data);
		}
		printf("%c ", p->data); //操作结点数据
		//当结点右标志位为1 时，直接找到其后继结点
		while (p->Rtag == Thread && p->rchild != NULL)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		//否则，按照中序遍历的规律，找其右子树中最左下的结点，也就是继续循环遍历
		p = p->rchild;
	}
}



//建立双向线索链表
void InOrderThread_Head(BiThrTree* h, BiThrTree t)
{
	//初始化头结点
	(*h) = (BiThrTree)malloc(sizeof(BiThrNode));
	if ((*h) == NULL) {
		printf("申请内存失败");
		return;
	}
	(*h)->rchild = *h;
	(*h)->Rtag = Link;
	//如果树本身是空树
	if (!t) {
		(*h)->lchild = *h;
		(*h)->Ltag = Link;
	}
	else {
		pre = *h;//pre 指向头结点
		(*h)->lchild = t;//头结点左孩子设为树根结点
		(*h)->Ltag = Link;
		InThreading(t);//线索化二叉树，pre 结点作为全局变量，线索化结束后，pre 结点指向中序序列中最后一个结点
		pre->rchild = *h;
		pre->Rtag = Thread;
		(*h)->rchild = pre;
	}
}

//中序正向遍历双向线索二叉树
void DoubleInOrderThraverse_Thr(BiThrTree h)
{
	BiThrTree p;
	p = h->lchild; //p 指向根结点
	while (p != h)
	{
		while (p->Ltag == Link) //当ltag = 0 时循环到中序序列的第一个结点
		{
			p = p->lchild;
		}
		printf("%c ", p->data); //显示结点数据，可以更改为其他对结点的操作
		while (p->Rtag == Thread && p->rchild != h)
		{
			p = p->rchild;
			printf("%c ", p->data);
		}
		p = p->rchild; //p 进入其右子树
	}
}