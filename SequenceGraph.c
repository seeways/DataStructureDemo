#include "SequenceGraph.h"


//���ݶ��㱾�����ݣ��жϳ������ڶ�ά�����е�λ��
int LocateVex(MGraph* G, VertexType v) {
	int i = 0;
	//����һά����(ͼ�Ķ�����)���ҵ�����v
	for (; i < G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	//����Ҳ����������ʾ��䣬����-1
	if (i > G->vexnum) {
		printf("û���Ŷ���.\n");
		return -1;
	}
	return i;
}

//��������ͼ
void CreateDG(MGraph* G) {
	//����ͼ���еĶ������ͱ���
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));

	//�������붥�㱾�������
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->vexs[i]));
	}
	//��ʼ����ά���󣬶���ȫ����0(��Ϊ��������)����Ϣָ��ָ��NULL
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}

	//�ڶ�ά��������ӱߵ�����
	for (int i = 0; i < G->arcnum; i++) {
		int v1, v2;
		//���뻡ͷ�ͻ�β
		scanf("%d,%d", &v1, &v2);
		//ȷ������λ��
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		//�ų���������
		if (m == -1 || n == -1) {
			printf("û��������� \n");
			return;
		}
		//����ȷ�Ļ������ݼ����ά����
		G->arcs[n][m].adj = 1;
	}
}

//��������ͼ
void CreateDN(MGraph* G) {
	//����ͼ���еĶ������ͱ���
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	//�������붥�㱾�������
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->vexs[i]));
	}
	//��ʼ����ά���󣬶���ȫ����0(��Ϊ��������)����Ϣָ��ָ��NULL
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	//�ڶ�ά��������ӱߵ�����
	for (int i = 0; i < G->arcnum; i++) {
		int v1, v2;
		//���뻡ͷ�ͻ�β
		scanf("%d,%d", &v1, &v2);
		// ȷ������λ��
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		//�ų���������
		if (m == -1 || n == -1) {
			printf("û��������� \n");
			return;
		}
		//����ͼ�Ķ��׾��������Խ��߶Գ�
		G->arcs[n][m].adj = 1;
		G->arcs[m][n].adj = 1;
	}
}

//������������������ͼ��ͬ���Ƕ��׾����д洢����Ȩֵ��
void CreateUDG(MGraph* G) {
	// ���붥�����ͱ���
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	// �������붥�㱾������
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->vexs[i]));
	}
	// ��ʼ����ά����
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// ��ӱߵ�����
	for (int i = 0; i < G->arcnum; i++) {
		int v1, v2, w;
		scanf("%d,%d,%d", &v1, &v2, &w);
		int n = LocateVex(G, v1);
		int m = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("û��������� \n");
			return;
		}
		// Ȩֵ
		G->arcs[n][m].adj = w;
	}
}
//������������������ͼΨһ��������Ƕ��׾����д洢����Ȩֵ
void CreateUDN(MGraph* G) {
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->vexs[i]));
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	for (int i = 0; i < G->arcnum; i++) {
		int v1, v2, w;
		scanf("%d,%d,%d", &v1, &v2, &w);
		int m = LocateVex(G, v1);
		int n = LocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("û��������� \n");
			return;
		}
		//����Գ�
		G->arcs[n][m].adj = w;
		G->arcs[m][n].adj = w;
	}
}

void CreateGraph(MGraph* G) {
	//ѡ��ͼ������
	scanf("%d", &(G->kind));
	//������ѡ���ͣ����ò�ͬ�ĺ���ʵ�ֹ���ͼ�Ĺ���
	switch (G->kind) {
	case DG:
		return CreateDG(G);
		break;
	case DN:
		return CreateDN(G);
		break;
	case UDG:
		return CreateUDG(G);
		break;
	case UDN:
		return CreateUDN(G);
		break;
	default:
		break;
	}
}
//�������
void PrintGrapth(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			printf("%d ", G.arcs[i][j].adj);
		}
		printf("\n");
	}
}