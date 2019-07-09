#pragma once
#ifndef GYLink

#include <stdio.h>
#include <stdlib.h>

// 广义表1
typedef struct GLNode1 {
	int tag;//标志域
	union {
		char atom;//原子结点的值域
		struct {
			struct GLNode1* hp, * tp;
		}ptr;//子表结点的指针域，hp指向表头；tp指向表尾
	};
}*Glist1;
Glist1 creatGlist1(Glist1 C);
int GlistLength1(Glist1 C);
int GlistDepth1(Glist1 C);

// 广义表2
typedef struct GLNode2 {
	int tag;//标志域
	union {
		char atom;//原子结点的值域
		struct GLNode2* hp;//子表结点的指针域，hp指向表头
	};
	struct GLNode2* tp;//这里的tp相当于链表的next指针，用于指向下一个数据元素
}*Glist2;

Glist2 creatGlist2(Glist2 C);
int GlistLength2(Glist2 C);

#endif // !GYLink
