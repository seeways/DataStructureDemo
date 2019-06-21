#include "blockLinkStorage.h"


//初始化链表，其中head为头指针，str为存储的字符串
blockLink* initblockLink(blockLink* head, char* str) {
	int length = strlen(str);
	//根据字符串的长度，计算出链表中使用节点的个数
	int num = length / blockLinkNum;
	if (length % blockLinkNum) {
		num++;
	}
	//创建并初始化首元节点
	head = (blockLink*)malloc(sizeof(blockLink));
	head->next = NULL;
	blockLink* temp = head;
	//初始化链表
	for (int i = 0; i < num; i++)
	{
		int j = 0;
		for (; j < blockLinkNum; j++)
		{
			if (i * blockLinkNum + j < length) {
				temp->a[j] = str[i * blockLinkNum + j];
			}
			else
				temp->a[j] = '#';
		}
		if (i * blockLinkNum + j < length)
		{
			blockLink* newlink = (blockLink*)malloc(sizeof(blockLink));
			newlink->next = NULL;
			temp->next = newlink;
			temp = newlink;
		}
	}
	return head;
}

void displayblockLink(blockLink* head) {
	blockLink* temp = head;
	while (temp) {
		for (int i = 0; i < blockLinkNum; i++) {
			printf("%c", temp->a[i]);
		}
		temp = temp->next;
	}
}
