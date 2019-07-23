#pragma once
#ifndef SequenceGraph

#include <stdio.h>
#define MAX_VERtEX_NUM 20                   //�����������
#define VRType int                          //��ʾ����֮��Ĺ�ϵ�ı�������
#define InfoType char                       //�洢�߶������Ϣָ���������
#define VertexType int                      //ͼ�ж������������
typedef enum { DG, DN, UDG, UDN }GraphKind;       //ö��ͼ�� 4 �����ͣ�����ͼ,������,����ͼ,������
typedef struct {
	VRType adj;                             //ͼ���� 1 �� 0 ��ʾ�Ƿ����ڣ�����ֱ��ΪȨֵ��0��
	InfoType* info;                        //�߶��⺬�е���Ϣָ��
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

// �ṹ
typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //�洢ͼ�ж�������
	AdjMatrix arcs;                         //��ά���飬��¼����֮��Ĺ�ϵ
	int vexnum, arcnum;                      //��¼ͼ�Ķ������ͱ���
	GraphKind kind;                         //��¼ͼ������
}MGraph;

// ����ͼ
void CreateGraph(MGraph* G);

// �������
void PrintGrapth(MGraph G);


#endif // !SequenceGraph
