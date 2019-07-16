#pragma once
#ifndef SaveTree

#include<stdio.h>
#include<stdlib.h>

// 双亲表示法
typedef struct Snode {//结点结构
	char data;//树中结点的数据类型
	int parent;//结点的父结点在数组中的位置下标
}PTNode;

typedef struct {//树结构
	PTNode tnode[20];//存放树中所有结点
	int n;//结点个数
}PTree;

//孩子表示法
typedef struct CTNode {
	int child;//链表中每个结点存储的不是数据本身，而是数据在数组中存储的位置下标
	struct CTNode* next;
}ChildPtr;
typedef struct {
	char data;//结点的数据类型
	ChildPtr* firstchild;//孩子链表的头指针
}CTBox;
typedef struct {
	CTBox nodes[20];//存储结点的数组
	int n, r;//结点数量和树根的位置
}CTree;

// 孩子兄弟表示法



// 初始化双亲结点
PTree InitPNode(PTree* tree);
void FindParent(PTree tree); // 寻找双亲结点

// 初始化孩子结点
CTree InitKidsTree(CTree* tree);
void findKids(CTree tree, char a); // 寻找孩子结点

#endif // !SaveTree
