#include "SaveTree.h"


PTree InitPNode(PTree* tree) {
	tree = (PTree*)malloc(sizeof(PTree));
	char ch = 'A';
	(*tree).n = 10;
	(*tree).tnode[0].data = 'R';
	(*tree).tnode[0].parent = -1;

	for (int i = 1; i < 10; i++)
	{
		(*tree).tnode[i].data = ch;

		switch (ch)
		{
		case 'A':
		case 'B':
		case 'C':
			(*tree).tnode[i].parent = 0;
			break;
		case 'D':
		case 'E':
			(*tree).tnode[i].parent = 1;
			break;
		case 'F':
			(*tree).tnode[i].parent = 3;
			break;
		case 'G':
		case 'H':
		case 'I':
			(*tree).tnode[i].parent = 6;
			break;
		default:
			break;
		}
		ch++;
	}
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%c %d\n", (*tree).tnode[i].data, (*tree).tnode[i].parent);
	//}
	return (*tree);
}
void FindParent(PTree tree)
{
	char a;
	int isfind = 0;
	printf("请输入要查询的结点值:\n");
	fflush(stdin);
	scanf("%c", &a);
	for (int i = 0; i < tree.n; i++) {
		if (tree.tnode[i].data == a) {
			isfind = 1;
			int ad = tree.tnode[i].parent;
			printf("%c的父节点为 %c,存储位置下标为 %d", a, tree.tnode[ad].data, ad);
			break;
		}
	}
	if (isfind == 0) {
		printf("树中无此节点");
	}
}

//孩子表示法存储普通树
CTree InitKidsTree(CTree *tree) {
	int n = 10;
	tree = (CTree*)malloc(sizeof(CTree));
	char ch = 'A';
	(*tree).n = n;

	// 初始化根节点
	(*tree).nodes[0].data = 'R';
	(*tree).nodes[0].firstchild = (ChildPtr*)malloc(sizeof(ChildPtr));
	(*tree).nodes[0].firstchild->next = NULL;
	ChildPtr* p = (*tree).nodes[0].firstchild;
	for (int j = 1; j <= 3; j++) {
		ChildPtr* newEle = (ChildPtr*)malloc(sizeof(ChildPtr));
		newEle->next = NULL;
		newEle->child = j;
		p->next = newEle;
		p = p->next;
	}

	for (int i = 1; i < n; i++) {

		(*tree).nodes[i].data = ch;
		(*tree).nodes[i].firstchild = (ChildPtr*)malloc(sizeof(ChildPtr));
		(*tree).nodes[i].firstchild->next = NULL;
		int Num,count=4;
		switch (ch)
		{
		case 'A': {
			Num = 2; break; 
		}
		case 'B':Num = 0; break;
		case 'C':Num = 1; break;
		case 'D':Num = 0; break;
		case 'E':Num = 0; break;
		case 'F':Num = 3; break;
		case 'G':Num = 0; break;
		case 'H':Num = 0; break;
		case 'I':Num = 0; break;
		}
		count += Num;
		if (Num != 0) {
			ChildPtr* p = (*tree).nodes[i].firstchild;
			for (int j = count; j < count+Num; j++) {
				ChildPtr* newEle = (ChildPtr*)malloc(sizeof(ChildPtr));
				newEle->next = NULL;
				newEle->child = j;
				p->next = newEle;
				p = p->next;
			}
		}

		ch++;
	}
	return (*tree);
}

// 寻找孩子结点
void findKids(CTree tree, char a) {
	int hasKids = 0;
	for (int i = 0; i < tree.n; i++) {
		if (tree.nodes[i].data == a) {
			ChildPtr* p = tree.nodes[i].firstchild->next;
			while (p) {
				hasKids = 1;
				printf("%c ", tree.nodes[p->child].data);
				p = p->next;
			}
			break;
		}
	}
	if (hasKids == 0) {
		printf("此节点为叶子节点");
	}
}

