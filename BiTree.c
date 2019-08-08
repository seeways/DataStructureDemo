#include "BiTree.h"


//��ʼ�����ĺ���
void CreateBiTree(BiTree* T) {
	// Ϊ���ڵ������ڴ棬����ֵ1
	*T = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->data = 1;
	// Ϊ���ڵ�������ӽڵ������ڴ�
	(*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	// ���ӽڵ�
	// Ϊ���ӽڵ㸳ֵ2����Ϊ���ӽڵ�������ӽڵ������ڴ�
	(*T)->lchild->data = 2;
	(*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
	// ���ӽڵ�����ӽڵ�
	// ��ֵ4����Ϊ�������ӽڵ㸳ֵNULL
	(*T)->lchild->lchild->data = 4;
	(*T)->lchild->lchild->lchild = NULL;
	(*T)->lchild->lchild->rchild = NULL;

	// ���ӽڵ�����ӽڵ�
	// ��ֵ5����Ϊ�������ӽڵ㸳ֵNULL
	(*T)->lchild->rchild->data = 5;
	(*T)->lchild->rchild->lchild = NULL;
	(*T)->lchild->rchild->rchild = NULL;

	// ���ӽڵ�
	// ��ֵ3����Ϊ�������ӽڵ������ڴ�
	(*T)->rchild->data = 3;
	(*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
	(*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));

	// ���ӽڵ�����ӽڵ�
	// ��ֵ6����Ϊ�������ӽڵ㸳ֵNULL
	(*T)->rchild->lchild->data = 6;
	(*T)->rchild->lchild->lchild = NULL;
	(*T)->rchild->lchild->rchild = NULL;

	// ���ӽڵ�����ӽڵ�
	// ��ֵ7����Ϊ�������ӽڵ㸳ֵNULL
	(*T)->rchild->rchild->data = 7;
	(*T)->rchild->rchild->lchild = NULL;
	(*T)->rchild->rchild->rchild = NULL;
}


//�������
void PreOrderTraverse(BiTree T) {
	if (T) {
		printf("%d ", T->data); //���ʸ��ڵ�
		PreOrderTraverse(T->lchild);//���ʸý�������
		PreOrderTraverse(T->rchild);//���ʸý����Һ���
	}
	//������Ϊ�գ�������һ��
	return;
}

//�������
void INOrderTraverse(BiTree T) {
	if (T) {
		INOrderTraverse(T->lchild);//��������
		printf("%d ", T->data);//���ʸ��ڵ�
		INOrderTraverse(T->rchild);//�����Һ���
	}
	//������Ϊ�գ�������һ��
	return;
}

//�������
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);//��������
		PostOrderTraverse(T->rchild);//�����Һ���
		printf("%d ", T->data);//���ʸ��ڵ�
	}
	//������Ϊ�գ�������һ��
	return;
}




// ��α���
void HierarchicalTraverse(BiTree node) {
	//��ʼ����ͷ�Ͷ�βָ�뿪ʼʱ��Ϊ0
	int front = 0, rear = 0;
	BiTNode* p;
	//����˳����У���ʼ��������������
	BiTree a[20];
	//��������
	a[rear++] = node;
	//����ͷ�Ͷ�β���ʱ����ʾ����Ϊ��
	while (front < rear) {
		//��ͷ������
		p = a[front++];
		printf("%d ", p->data);
		//����ͷ�������Һ����������
		if (p->lchild != NULL) {
			a[rear++] = p->lchild;
		}
		if (p->rchild != NULL) {
			a[rear++] = p->rchild;
		}
	}
}