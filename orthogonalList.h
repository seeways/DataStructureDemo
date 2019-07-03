#pragma once
#ifndef orthogonalList
// ʮ������ѹ��ϡ�����
#include<stdio.h>
#include<stdlib.h>

// ʮ������ڵ�
typedef struct OLNode
{
	int i, j, e; //������Ԫ��i������ j������ e����ǰλ�õ�����
	struct OLNode* right, * down; //ָ���� ��ָ�� ��ָ��
}OLNode, * OLink;
//ʮ������ṹ
typedef struct
{
	OLink* rhead, * chead; //�к�������ͷָ��
	int mu, nu, tu;  //���������,�����ͷ���Ԫ�ĸ���
}CrossList;
// ����ʮ���������
CrossList CreateMatrix_OL(CrossList M);
// ��ӡʮ������
void OLDisplay(CrossList M);

#endif // !orthogonalList
