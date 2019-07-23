#pragma once
#ifndef SequenceGraph

#include <stdio.h>
#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储边额外的信息指针变量类型
#define VertexType int                      //图中顶点的数据类型
typedef enum { DG, DN, UDG, UDN }GraphKind;       //枚举图的 4 种类型：有向图,有向网,无向图,无向网
typedef struct {
	VRType adj;                             //图，用 1 或 0 表示是否相邻；网，直接为权值或0。
	InfoType* info;                        //边额外含有的信息指针
}ArcCell, AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

// 结构
typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
	AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
	int vexnum, arcnum;                      //记录图的顶点数和边数
	GraphKind kind;                         //记录图的种类
}MGraph;

// 创建图
void CreateGraph(MGraph* G);

// 输出函数
void PrintGrapth(MGraph G);


#endif // !SequenceGraph
