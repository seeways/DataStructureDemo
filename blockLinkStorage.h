#pragma once
#ifndef blockLinkStorage

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define blockLinkNum 3//全局设置链表中节点存储数据的个数
typedef struct blockLink {
	char a[blockLinkNum]; //数据域可存放 blockLinkNum 个数据
	struct blockLink* next; //代表指针域，指向直接后继元素
}blockLink; // nk为节点名，每个节点都是一个 link 结构体
blockLink* initblockLink(blockLink* head, char* str);
void displayblockLink(blockLink* head);

#endif // !blockLinkStorage

