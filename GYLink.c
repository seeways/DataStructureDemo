#include "GYLink.h"

// 广义表1
Glist1 creatGlist1(Glist1 C) {
	//广义表C
	C = (Glist1)malloc(sizeof(Glist1));
	C->tag = 1;
	//表头原子‘a’
	C->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.hp->tag = 0;
	C->ptr.hp->atom = 'a';
	//表尾子表（b,c,d）,是一个整体
	C->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.tp = NULL;
	//开始存放下一个数据元素（b,c,d）,表头为‘b’，表尾为（c,d）
	C->ptr.tp->ptr.hp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.hp->atom = 'b';
	C->ptr.tp->ptr.hp->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	//存放子表(c,d)，表头为c，表尾为d
	C->ptr.tp->ptr.hp->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom = 'c';
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp = (Glist1)malloc(sizeof(Glist1));
	//存放表尾d
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->tag = 1;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp = (Glist1)malloc(sizeof(Glist1));
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->tag = 0;
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom = 'd';
	C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.tp = NULL;
	return C;
}

// 广义表1 的长度
int GlistLength1(Glist1 C) {
	int Number = 0;
	Glist1 P = C;
	while (P) {
		Number++;
		P = P->ptr.tp;
	}
	return Number;
}


int GlistDepth1(Glist1 C) {
	//如果表C 为空表时，直接返回长度1；
	if (!C) {
		return 1;
	}
	//如果表C 为原子时，直接返回0；
	if (C->tag == 0) {
		return 0;
	}
	int max = 0;//设置表C 的初始长度为0；
	for (Glist1 pp = C; pp; pp = pp->ptr.tp) {
		int dep = GlistDepth1(pp->ptr.hp);
		if (dep > max) {
			max = dep;//每次找到表中遍历到深度最大的表，并用max 记录
		}
	}
	//程序运行至此处，表明广义表不是空表，由于原子返回的是0，而实际长度是1，所以，此处要+1；
	return max + 1;
}


// 广义表2
Glist2 creatGlist2(Glist2 C) {
	C = (Glist2)malloc(sizeof(Glist2));
	C->tag = 1;
	C->hp = (Glist2)malloc(sizeof(Glist2));
	C->tp = NULL;
	//表头原子a
	C->hp->tag = 0;
	C->atom = 'a';

	C->hp->tp = (Glist2)malloc(sizeof(Glist2));
	C->hp->tp->tag = 1;
	C->hp->tp->hp = (Glist2)malloc(sizeof(Glist2));
	C->hp->tp->tp = NULL;
	//原子b
	C->hp->tp->hp->tag = 0;
	C->hp->tp->hp->atom = 'b';
	C->hp->tp->hp->tp = (Glist2)malloc(sizeof(Glist2));
	//原子c
	C->hp->tp->hp->tp->tag = 0;
	C->hp->tp->hp->tp->atom = 'c';
	C->hp->tp->hp->tp->tp = (Glist2)malloc(sizeof(Glist2));
	//原子d
	C->hp->tp->hp->tp->tp->tag = 0;
	C->hp->tp->hp->tp->tp->atom = 'd';
	C->hp->tp->hp->tp->tp->tp = NULL;
	return C;
}

// 广义表2 的长度
int GlistLength2(Glist2 C) {
	int Number = 0;
	Glist2 P = C;
	while (P) {
		if (P->tag == 0)
		{
			printf("tag=0 %c %d ", P->atom, Number);
			Number++;
			P = P->tp;
		}else if (P->tag == 1) {
			Number++;
			printf("tag=1 %d ", Number);
			P = P->hp;
		}
	}
	return Number;
}

