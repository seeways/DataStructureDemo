#include "orthogonalList.h"

CrossList CreateMatrix_OL(CrossList M)
{
	int m, n, t; // ����������������������0Ԫ�ظ���
	int i, j, e; // ����ڵ����������������ǰλ�õ�����
	OLNode* p, * q; // �����к��нڵ�
	printf("�������������������ͷ�0Ԫ�ظ�����");
	scanf("%d%d%d", &m, &n, &t);
	M.mu = m;
	M.nu = n;
	M.tu = t;
	// Ϊ�к��еı�ͷָ������ڴ�
	if (!(M.rhead = (OLink*)malloc((m + 1) * sizeof(OLink))) || !(M.chead = (OLink*)malloc((n + 1) * sizeof(OLink))))
	{
		printf("��ʼ������ʧ��");
		exit(0);
	}
	// ����������ʼ����ָ��
	for (i = 1; i <= m; i++)
	{
		M.rhead[i] = NULL;
	}
	// ����������ʼ����ָ��
	for (j = 1; j <= n; j++)
	{
		M.chead[j] = NULL;
	}
	printf("�����У��У���ǰλ�ã�����0 0 0��ʾ������\n");
	// �����У��У���ǰλ�ã������ǰλ�ã�=0�����������
	for (scanf("%d%d%d", &i, &j, &e); 0 != i; scanf("%d%d%d", &i, &j, &e)) {
		if (!(p = (OLNode*)malloc(sizeof(OLNode))))
		{
			printf("��ʼ����Ԫ��ʧ��");
			exit(0);
		}
		p->i = i;
		p->j = j;
		p->e = e;
		//���ӵ��е�ָ��λ��
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
		//���ӵ��е�ָ��λ��
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