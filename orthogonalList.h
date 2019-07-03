#pragma once
#ifndef orthogonalList
// 十字链表法压缩稀疏矩阵
#include<stdio.h>
#include<stdlib.h>

// 十字链表节点
typedef struct OLNode
{
	int i, j, e; //矩阵三元组i代表行 j代表列 e代表当前位置的数据
	struct OLNode* right, * down; //指针域 右指针 下指针
}OLNode, * OLink;
//十字链表结构
typedef struct
{
	OLink* rhead, * chead; //行和列链表头指针
	int mu, nu, tu;  //矩阵的行数,列数和非零元的个数
}CrossList;
// 创建十字链表矩阵
CrossList CreateMatrix_OL(CrossList M);
// 打印十字链表
void OLDisplay(CrossList M);

#endif // !orthogonalList
