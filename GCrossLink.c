
#include "GCrossLink.h"


int GCrossLinkLocateVex(OLGraph* G, VertexType v) {
	int i = 0;
	//����һά���飬�ҵ�����v
	for (; i < G->vexnum; i++) {
		if (G->xlist[i].data == v) {
			break;
		}
	}
	//����Ҳ����������ʾ��䣬���� -1
	if (i > G->vexnum) {
		printf("no such vertex.\n");
		return -1;
	}
	return i;
}
//����ʮ��������
void CreateGCrossLinkDG(OLGraph* G) {
	//��������ͼ�Ķ������ͻ���
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	//ʹ��һά����洢�������ݣ���ʼ��ָ����ΪNULL
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->xlist[i].data));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	//����ʮ������
	for (int k = 0; k < G->arcnum; k++) {
		int v1, v2;
		scanf("%d,%d", &v1, &v2);
		//ȷ��v1��v2�������е�λ���±�
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		//�������Ľ��
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = i;
		p->headvex = j;
		//����ͷ�巨�����µ�p���
		p->hlik = G->xlist[j].firstin;
		p->tlink = G->xlist[i].firstout;
		G->xlist[j].firstin = G->xlist[i].firstout = p;
	}
}