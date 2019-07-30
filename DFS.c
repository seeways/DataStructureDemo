#include "DFS.h"

//根据顶点本身数据，判断出顶点在二维数组中的位置
int DFSLocateVex(DFSMGraph* G, VertexType v) {
	int i = 0;
	//遍历一维数组，找到变量v
	for (; i < G->vexnum; i++) {
		if (G->vexs[i] == v) {
			break;
		}
	}
	//如果找不到，输出提示语句，返回-1
	if (i > G->vexnum) {
		printf("no such vertex.\n");
		return -1;
	}
	return i;
}

//构造无向图
void CreateDFSDN(DFSMGraph* G) {
	// 输入顶点数和边数
	scanf("%d,%d", &(G->vexnum), &(G->arcnum));
	for (int i = 0; i < G->vexnum; i++) {
		// 输入顶点数据
		scanf("%d", &(G->vexs[i]));
	}
	// 初始化二维数组
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j].adj = 0;
			G->arcs[i][j].info = NULL;
		}
	}
	// 输入顶点位置
	for (int i = 0; i < G->arcnum; i++) {
		int v1, v2;
		scanf("%d,%d", &v1, &v2);
		int n = DFSLocateVex(G, v1);
		int m = DFSLocateVex(G, v2);
		if (m == -1 || n == -1) {
			printf("no this vertex\n");
			return;
		}
		G->arcs[n][m].adj = 1;
		G->arcs[m][n].adj = 1;//无向图的二阶矩阵沿主对角线对称
	}
}

// 查询是否相邻的下标
int FirstAdjVex(DFSMGraph G, int v)
{
	//查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[v][i].adj) {
			return i;
		}
	}
	return -1;
}

// 
int NextAdjVex(DFSMGraph G, int v, int w)
{
	//从前一个访问位置w的下一个位置开始，查找之间有边的顶点
	for (int i = w + 1; i < G.vexnum; i++) {
		if (G.arcs[v][i].adj) {
			return i;
		}
	}
	return -1;
}
void visitVex(DFSMGraph G, int v) {
	printf("%d ", G.vexs[v]);
}
void DFS(DFSMGraph G, int v) {
	visited[v] = true;//标记为true
	visitVex(G, v); //访问第v 个顶点
	//从该顶点的第一个边开始，一直到最后一个边，对处于边另一端的顶点调用DFS函数
	for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
		//如果该顶点的标记位false，证明未被访问，调用深度优先搜索函数
		if (!visited[w]) {
			DFS(G, w);
		}
	}
}
//深度优先搜索
void DFSTraverse(DFSMGraph G) {//
	int v;
	//将用做标记的visit数组初始化为false
	for (v = 0; v < G.vexnum; ++v) {
		visited[v] = false;
	}
	//对于每个标记为false的顶点调用深度优先搜索函数
	for (v = 0; v < G.vexnum; v++) {
		//如果该顶点的标记位为false，则调用深度优先搜索函数
		if (!visited[v]) {
			DFS(G, v);
		}
	}
}
