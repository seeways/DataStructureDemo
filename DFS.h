#pragma once
#ifndef DeepFirstlySearch

#include <stdio.h>

#define MAX_VERtEX_NUM 20                   //�����������
#define VRType int                          //��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char                       //�洢�����߱߶�����Ϣ��ָ���������
#define VertexType int                      //ͼ�ж������������

typedef enum { false, true }bool;               //����bool�ͳ���
bool visited[MAX_VERtEX_NUM];               //����ȫ�����飬��¼��Ƕ����Ƿ񱻷��ʹ�

typedef struct {
	VRType adj;                             //������Ȩͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ����ڴ�Ȩͼ��ֱ��ΪȨֵ��
	InfoType* info;                        //����߶��⺬�е���Ϣָ��
}DFSArcCell, DFSAdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
	DFSAdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
	int vexnum, arcnum;                      //��¼ͼ�Ķ������ͻ����ߣ���
}DFSMGraph;


//��������ͼ
void CreateDFSDN(DFSMGraph* G);


//�����������
void DFSTraverse(DFSMGraph G);



#endif // !DeepFirstlySearch
