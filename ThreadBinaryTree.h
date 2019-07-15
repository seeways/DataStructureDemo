#pragma once
#ifndef ThreadBinaryTree

#include <stdio.h>
#include <stdlib.h>

#define TElemType char//宏定义，结点中数据域的类型

//枚举，Link 为0，Thread 为1
typedef enum {
	Link,
	Thread
}PointerTag;

//结点结构构造
typedef struct BiThrNode {
	TElemType data;//数据域
	struct BiThrNode* lchild, * rchild;//左孩子，右孩子指针域
	PointerTag Ltag, Rtag;//标志域，枚举类型
}BiThrNode, * BiThrTree;

//中序和后序只需改变赋值语句的位置即可
void CreateTree(BiThrTree* tree);

//中序对二叉树进行线索化
void InThreading(BiThrTree p);

//中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p);

//建立双向线索链表
void InOrderThread_Head(BiThrTree* h, BiThrTree t);

//中序正向遍历双向线索二叉树
void DoubleInOrderThraverse_Thr(BiThrTree h);


#endif // !ThreadBinaryTree
