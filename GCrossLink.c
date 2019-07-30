
#include "GCrossLink.h"


int GCrossLinkLocateVex(OLGraph* G, VertexType v) {
	int i = 0;
	//遍历一维数组，找到变量v
	for (; i < G->vexnum; i++) {
		if (G->xlist[i].data == v) {
			break;
		}
	}
	//如果找不到，输出提示语句，返回 -1
	if (i > G->vexnum) {
		printf("no such vertex.\n");
		return -1;
	}
	return i;
}
//构建十字链表函数
void CreateGCrossLinkDG(OLGraph* G) {
	//输入有向图的顶点数和弧数
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	//使用一维数组存储顶点数据，初始化指针域为NULL
	for (int i = 0; i < G->vexnum; i++) {
		scanf("%d", &(G->xlist[i].data));
		G->xlist[i].firstin = NULL;
		G->xlist[i].firstout = NULL;
	}
	//构建十字链表
	for (int k = 0; k < G->arcnum; k++) {
		int v1, v2;
		scanf("%d,%d", &v1, &v2);
		//确定v1、v2在数组中的位置下标
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		//建立弧的结点
		ArcBox* p = (ArcBox*)malloc(sizeof(ArcBox));
		p->tailvex = i;
		p->headvex = j;
		//采用头插法插入新的p结点
		p->hlik = G->xlist[j].firstin;
		p->tlink = G->xlist[i].firstout;
		G->xlist[j].firstin = G->xlist[i].firstout = p;
	}
}