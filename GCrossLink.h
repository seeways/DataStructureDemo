#pragma once
#ifndef GCrossLink
// �洢ͼ��ʮ������洢�ṹ

#include <stdio.h>

#define  MAX_VERTEX_NUM 20
#define  InfoType int //ͼ�л�������Ϣ����������
#define  VertexType int 

typedef struct ArcBox {
	int tailvex, headvex;//��β����ͷ��Ӧ�����������е�λ���±�
	struct ArcBox* hlik, * tlink;//�ֱ�ָ��ͷ��ͬ�ͻ�β��ͬ����һ����
	InfoType* info;//�洢�������Ϣ��ָ��
}ArcBox;
typedef struct VexNode {
	VertexType data;//�����������
	ArcBox* firstin, * firstout;//ָ���Ըö���Ϊ��ͷ�ͻ�β�������׸����
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];//�洢�����һά����
	int vexnum, arcnum;//��¼ͼ�Ķ������ͻ���
}OLGraph;

//����ʮ��������
void CreateGCrossLinkDG(OLGraph* G);

#endif // !GCrossLink
