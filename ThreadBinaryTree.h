#pragma once
#ifndef ThreadBinaryTree

#include <stdio.h>
#include <stdlib.h>

#define TElemType char//�궨�壬����������������

//ö�٣�Link Ϊ0��Thread Ϊ1
typedef enum {
	Link,
	Thread
}PointerTag;

//���ṹ����
typedef struct BiThrNode {
	TElemType data;//������
	struct BiThrNode* lchild, * rchild;//���ӣ��Һ���ָ����
	PointerTag Ltag, Rtag;//��־��ö������
}BiThrNode, * BiThrTree;

//����ͺ���ֻ��ı丳ֵ����λ�ü���
void CreateTree(BiThrTree* tree);

//����Զ���������������
void InThreading(BiThrTree p);

//�����������������
void InOrderThraverse_Thr(BiThrTree p);

//����˫����������
void InOrderThread_Head(BiThrTree* h, BiThrTree t);

//�����������˫������������
void DoubleInOrderThraverse_Thr(BiThrTree h);


#endif // !ThreadBinaryTree
