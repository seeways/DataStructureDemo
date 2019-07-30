#pragma once
#ifndef DeepFirstlySearch

#include <stdio.h>

#define MAX_VERtEX_NUM 20                   //顶点的最大个数
#define VRType int                          //表示顶点之间的关系的变量类型
#define InfoType char                       //存储弧或者边额外信息的指针变量类型
#define VertexType int                      //图中顶点的数据类型

typedef enum { false, true }bool;               //定义bool型常量
bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过

typedef struct {
	VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
	InfoType* info;                        //弧或边额外含有的信息指针
}DFSArcCell, DFSAdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];

typedef struct {
	VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
	DFSAdjMatrix arcs;                         //二维数组，记录顶点之间的关系
	int vexnum, arcnum;                      //记录图的顶点数和弧（边）数
}DFSMGraph;


//构造无向图
void CreateDFSDN(DFSMGraph* G);


//深度优先搜索
void DFSTraverse(DFSMGraph G);



#endif // !DeepFirstlySearch
