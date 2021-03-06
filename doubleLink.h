#pragma once
#ifndef doubleLink
#include <stdio.h>
#include <stdlib.h>

typedef struct doubleLinkLine {
	struct doubleLinkLine* prior; //指向直接前趋
	int data;
	struct doubleLinkLine* next; //指向直接后继
}doubleLinkLine;
/*
	双向链表
*/
//双链表的创建
doubleLinkLine* initDoubleLinkLine(doubleLinkLine* head);
//双链表插入元素，add表示插入位置
doubleLinkLine* insertDoubleLinkLine(doubleLinkLine* head, int data, int add);
//双链表删除指定元素
doubleLinkLine* delDoubleLinkLine(doubleLinkLine* head, int data);
//双链表中查找指定元素
int selectDoubleLinkElem(doubleLinkLine* head, int elem);
//双链表中更改指定位置节点中存储的数据，add表示更改位置
doubleLinkLine* amendDoubleLinkElem(doubleLinkLine* p, int add, int newElem);
//输出双链表的实现函数
void displayDoubleLink(doubleLinkLine* head);

/*
	双向循环链表
*/
doubleLinkLine* initDoubleRingLinkLine(doubleLinkLine* head);
void displayDoubleRingLink(doubleLinkLine* head);

#endif // !doubleLink
