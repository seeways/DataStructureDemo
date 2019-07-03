#include "orthogonalList.h"

CrossList CreateMatrix_OL(CrossList M)
{
	int m, n, t; // 定义矩阵的行数，列数，非0元素个数
	int i, j, e; // 定义节点的行数，列数，当前位置的数据
	OLNode* p, * q; // 定义行和列节点
	printf("输入矩阵的行数、列数和非0元素个数：");
	scanf("%d%d%d", &m, &n, &t);
	M.mu = m;
	M.nu = n;
	M.tu = t;
	// 为行和列的表头指针分配内存
	if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
	{
		printf("初始化矩阵失败");
		exit(0);
	}
	// 根据行数初始化行指针
	for (i = 1; i <= m; i++)
	{
		M.rhead[i] = NULL;
	}
	// 根据列数初始化列指针
	for (j = 1; j <= n; j++)
	{
		M.chead[j] = NULL;
	}
	printf("输入行，列，当前位置，输入0 0 0表示结束：\n");
	// 输入行，列，当前位置，如果当前位置！=0，则继续输入
	for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e)) {
		if (!(p = (OLNode*)malloc(sizeof(OLNode))))
		{
			printf("初始化三元组失败");
			exit(0);
		}
		p->i = i;
		p->j = j;
		p->e = e;
		//链接到行的指定位置
		if (NULL == M.rhead[i] || M.rhead[i]->j > j)
		{
			p->right = M.rhead[i];
			M.rhead[i] = p;
		}
		else
		{
			for (q = M.rhead[i]; (q->right) && q->right->j < j; q = q->right);
			p->right = q->right;
			q->right = p;
		}
		//链接到列的指定位置
		if (NULL == M.chead[j] || M.chead[j]->i > i)
		{
			p->down = M.chead[j];
			M.chead[j] = p;
		}
		else
		{
			for (q = M.chead[j]; (q->down) && q->down->i < i; q = q->down);
			p->down = q->down;
			q->down = p;
		}
	}
	return M;
}
void OLDisplay(CrossList M) {
	for (int i = 1; i <= M.nu; i++)
	{
		if (NULL != M.chead[i])
		{
			OLink p = M.chead[i];
			while (NULL != p)
			{
				printf("%d\t%d\t%d\n", p->i, p->j, p->e);
				p = p->down;
			}
		}
	}
}