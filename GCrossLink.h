#pragma once
#ifndef GCrossLink
// 存储图的十字链表存储结构

#include <stdio.h>

#define  MAX_VERTEX_NUM 20
#define  InfoType int //图中弧包含信息的数据类型
#define  VertexType int 

typedef struct ArcBox {
	int tailvex, headvex;//弧尾、弧头对应顶点在数组中的位置下标
	struct ArcBox* hlik, * tlink;//分别指向弧头相同和弧尾相同的下一个弧
	InfoType* info;//存储弧相关信息的指针
}ArcBox;
typedef struct VexNode {
	VertexType data;//顶点的数据域
	ArcBox* firstin, * firstout;//指向以该顶点为弧头和弧尾的链表首个结点
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];//存储顶点的一维数组
	int vexnum, arcnum;//记录图的顶点数和弧数
}OLGraph;

//构建十字链表函数
void CreateGCrossLinkDG(OLGraph* G);

#endif // !GCrossLink
