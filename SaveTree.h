#pragma once
#ifndef SaveTree

#include<stdio.h>
#include<stdlib.h>

// ˫�ױ�ʾ��
typedef struct Snode {//���ṹ
	char data;//���н�����������
	int parent;//���ĸ�����������е�λ���±�
}PTNode;

typedef struct {//���ṹ
	PTNode tnode[20];//����������н��
	int n;//������
}PTree;

//���ӱ�ʾ��
typedef struct CTNode {
	int child;//������ÿ�����洢�Ĳ������ݱ������������������д洢��λ���±�
	struct CTNode* next;
}ChildPtr;
typedef struct {
	char data;//������������
	ChildPtr* firstchild;//���������ͷָ��
}CTBox;
typedef struct {
	CTBox nodes[20];//�洢��������
	int n, r;//���������������λ��
}CTree;

// �����ֵܱ�ʾ��



// ��ʼ��˫�׽��
PTree InitPNode(PTree* tree);
void FindParent(PTree tree); // Ѱ��˫�׽��

// ��ʼ�����ӽ��
CTree InitKidsTree(CTree* tree);
void findKids(CTree tree, char a); // Ѱ�Һ��ӽ��

#endif // !SaveTree
